#!/usr/bin/env python3

import os
import re
import shutil
import subprocess
import gzip
from pathlib import Path

from argparse import ArgumentParser, RawTextHelpFormatter

import sys

SCRIPT_DIR = os.getcwd()

def generate_constants():
	# generate constants.js file
	with open("{}/src/Comms.cpp".format(SCRIPT_DIR)) as comms_file, open("{}/data_src/constants.js".format(SCRIPT_DIR), "w") as constants_file:
		regex = re.compile("#define (RESPONSE_|CONTROL_|EXTENDED_|BINARY_)")
		for line in comms_file:
			if re.match(regex, line):
				values = line.split(" ")
				values = list(filter(" ".__ne__, values))
				values = list(filter("".__ne__, values))
				values[2] = values[2].rstrip()
				constants_file.write("export const {} = {};\n".format(values[1], values[2]))

def generate_terser(terser_binary: str):
	# use terser if present
	if shutil.which(terser_binary) is not None or os.path.isfile(terser_binary):
		print("Using terser")
		for js_file in os.listdir("{}/data".format(SCRIPT_DIR)):
			if js_file.endswith(".js"):
				cmd = [terser_binary, "-c", "toplevel", "-m", "reserved,toplevel,eval", "-o", "{}/data/{}".format(SCRIPT_DIR, js_file), "{}/data/{}".format(SCRIPT_DIR, js_file)]
				subprocess.run(cmd)


def copy_files():
	shutil.rmtree("{}/data".format(SCRIPT_DIR), ignore_errors=True)
	shutil.copytree("{}/data_src".format(SCRIPT_DIR), "{}/data".format(SCRIPT_DIR))

def generate_gzip():
	# gzip all files
	for root, dirs, files in os.walk("{}/data".format(SCRIPT_DIR)):
		for curr_file in files:
			curr_file = "{}/{}".format(root, curr_file)
			to_compress = None
			with open(curr_file, "rb") as f:
				to_compress = f.read()
			with gzip.open(curr_file, "wb") as f:
				f.write(to_compress)


if __name__ == "__main__" or __name__ == "SCons.Script":
	parser = ArgumentParser(formatter_class=RawTextHelpFormatter)
	parser.add_argument("--terser", dest="terser", help="Terser cmd [Default: %(default)s]", type=str, default= "{}/node_modules/terser/bin/terser".format(str(Path.home())))
	args, unknown = parser.parse_known_args()

	generate_constants()
	copy_files()
	generate_terser(args.terser)
	generate_gzip()
