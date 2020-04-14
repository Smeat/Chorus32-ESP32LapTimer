/*
 * This file is part of Chorus32-ESP32LapTimer 
 * (see https://github.com/AlessandroAU/Chorus32-ESP32LapTimer).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FONT_h
#define FONT_h

// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version! 
const uint8_t Dialog_plain_9[] PROGMEM = {
  0x0A, // Width: 10
  0x0C, // Height: 12
  0x20, // First Char: 32
  0xE0, // Numbers of Chars: 224

  // Jump Table:
  0xFF, 0xFF, 0x00, 0x03,  // 32:65535
  0x00, 0x00, 0x04, 0x03,  // 33:0
  0x00, 0x04, 0x07, 0x04,  // 34:4
  0x00, 0x0B, 0x0D, 0x08,  // 35:11
  0x00, 0x18, 0x09, 0x06,  // 36:24
  0x00, 0x21, 0x10, 0x09,  // 37:33
  0x00, 0x31, 0x0E, 0x08,  // 38:49
  0x00, 0x3F, 0x03, 0x02,  // 39:63
  0x00, 0x42, 0x06, 0x04,  // 40:66
  0x00, 0x48, 0x05, 0x04,  // 41:72
  0x00, 0x4D, 0x09, 0x05,  // 42:77
  0x00, 0x56, 0x0B, 0x08,  // 43:86
  0x00, 0x61, 0x04, 0x03,  // 44:97
  0x00, 0x65, 0x05, 0x03,  // 45:101
  0x00, 0x6A, 0x04, 0x03,  // 46:106
  0x00, 0x6E, 0x05, 0x03,  // 47:110
  0x00, 0x73, 0x09, 0x06,  // 48:115
  0x00, 0x7C, 0x0A, 0x06,  // 49:124
  0x00, 0x86, 0x0A, 0x06,  // 50:134
  0x00, 0x90, 0x09, 0x06,  // 51:144
  0x00, 0x99, 0x0B, 0x06,  // 52:153
  0x00, 0xA4, 0x09, 0x06,  // 53:164
  0x00, 0xAD, 0x09, 0x06,  // 54:173
  0x00, 0xB6, 0x09, 0x06,  // 55:182
  0x00, 0xBF, 0x09, 0x06,  // 56:191
  0x00, 0xC8, 0x09, 0x06,  // 57:200
  0x00, 0xD1, 0x04, 0x03,  // 58:209
  0x00, 0xD5, 0x04, 0x03,  // 59:213
  0x00, 0xD9, 0x0E, 0x08,  // 60:217
  0x00, 0xE7, 0x0D, 0x08,  // 61:231
  0x00, 0xF4, 0x0D, 0x08,  // 62:244
  0x01, 0x01, 0x09, 0x05,  // 63:257
  0x01, 0x0A, 0x11, 0x0A,  // 64:266
  0x01, 0x1B, 0x0C, 0x06,  // 65:283
  0x01, 0x27, 0x0B, 0x07,  // 66:295
  0x01, 0x32, 0x0C, 0x07,  // 67:306
  0x01, 0x3E, 0x0B, 0x07,  // 68:318
  0x01, 0x49, 0x0A, 0x06,  // 69:329
  0x01, 0x53, 0x09, 0x06,  // 70:339
  0x01, 0x5C, 0x0B, 0x07,  // 71:348
  0x01, 0x67, 0x0C, 0x07,  // 72:359
  0x01, 0x73, 0x04, 0x03,  // 73:371
  0x01, 0x77, 0x04, 0x03,  // 74:375
  0x01, 0x7B, 0x0C, 0x06,  // 75:379
  0x01, 0x87, 0x0A, 0x05,  // 76:391
  0x01, 0x91, 0x0E, 0x08,  // 77:401
  0x01, 0x9F, 0x0C, 0x07,  // 78:415
  0x01, 0xAB, 0x0B, 0x07,  // 79:427
  0x01, 0xB6, 0x09, 0x06,  // 80:438
  0x01, 0xBF, 0x0B, 0x07,  // 81:447
  0x01, 0xCA, 0x0C, 0x06,  // 82:458
  0x01, 0xD6, 0x0B, 0x07,  // 83:470
  0x01, 0xE1, 0x09, 0x05,  // 84:481
  0x01, 0xEA, 0x0B, 0x07,  // 85:490
  0x01, 0xF5, 0x0B, 0x06,  // 86:501
  0x02, 0x00, 0x0D, 0x07,  // 87:512
  0x02, 0x0D, 0x0C, 0x06,  // 88:525
  0x02, 0x19, 0x09, 0x05,  // 89:537
  0x02, 0x22, 0x0A, 0x05,  // 90:546
  0x02, 0x2C, 0x06, 0x04,  // 91:556
  0x02, 0x32, 0x06, 0x03,  // 92:562
  0x02, 0x38, 0x06, 0x04,  // 93:568
  0x02, 0x3E, 0x0B, 0x08,  // 94:574
  0x02, 0x49, 0x0A, 0x05,  // 95:585
  0x02, 0x53, 0x05, 0x05,  // 96:595
  0x02, 0x58, 0x0A, 0x06,  // 97:600
  0x02, 0x62, 0x09, 0x06,  // 98:610
  0x02, 0x6B, 0x0A, 0x06,  // 99:619
  0x02, 0x75, 0x0A, 0x06,  // 100:629
  0x02, 0x7F, 0x0A, 0x06,  // 101:639
  0x02, 0x89, 0x05, 0x03,  // 102:649
  0x02, 0x8E, 0x0A, 0x06,  // 103:654
  0x02, 0x98, 0x0A, 0x06,  // 104:664
  0x02, 0xA2, 0x04, 0x03,  // 105:674
  0x02, 0xA6, 0x04, 0x03,  // 106:678
  0x02, 0xAA, 0x0A, 0x05,  // 107:682
  0x02, 0xB4, 0x04, 0x03,  // 108:692
  0x02, 0xB8, 0x10, 0x09,  // 109:696
  0x02, 0xC8, 0x0A, 0x06,  // 110:712
  0x02, 0xD2, 0x09, 0x06,  // 111:722
  0x02, 0xDB, 0x09, 0x06,  // 112:731
  0x02, 0xE4, 0x0A, 0x06,  // 113:740
  0x02, 0xEE, 0x07, 0x04,  // 114:750
  0x02, 0xF5, 0x08, 0x05,  // 115:757
  0x02, 0xFD, 0x08, 0x04,  // 116:765
  0x03, 0x05, 0x0A, 0x06,  // 117:773
  0x03, 0x0F, 0x09, 0x05,  // 118:783
  0x03, 0x18, 0x0D, 0x07,  // 119:792
  0x03, 0x25, 0x0A, 0x05,  // 120:805
  0x03, 0x2F, 0x09, 0x05,  // 121:815
  0x03, 0x38, 0x0A, 0x06,  // 122:824
  0x03, 0x42, 0x08, 0x05,  // 123:834
  0x03, 0x4A, 0x04, 0x03,  // 124:842
  0x03, 0x4E, 0x07, 0x05,  // 125:846
  0x03, 0x55, 0x0D, 0x08,  // 126:853
  0x03, 0x62, 0x0A, 0x05,  // 127:866
  0x03, 0x6C, 0x0A, 0x05,  // 128:876
  0x03, 0x76, 0x0A, 0x05,  // 129:886
  0x03, 0x80, 0x0A, 0x05,  // 130:896
  0x03, 0x8A, 0x0A, 0x05,  // 131:906
  0x03, 0x94, 0x0A, 0x05,  // 132:916
  0x03, 0x9E, 0x0A, 0x05,  // 133:926
  0x03, 0xA8, 0x0A, 0x05,  // 134:936
  0x03, 0xB2, 0x0A, 0x05,  // 135:946
  0x03, 0xBC, 0x0A, 0x05,  // 136:956
  0x03, 0xC6, 0x0A, 0x05,  // 137:966
  0x03, 0xD0, 0x0A, 0x05,  // 138:976
  0x03, 0xDA, 0x0A, 0x05,  // 139:986
  0x03, 0xE4, 0x0A, 0x05,  // 140:996
  0x03, 0xEE, 0x0A, 0x05,  // 141:1006
  0x03, 0xF8, 0x0A, 0x05,  // 142:1016
  0x04, 0x02, 0x0A, 0x05,  // 143:1026
  0x04, 0x0C, 0x0A, 0x05,  // 144:1036
  0x04, 0x16, 0x0A, 0x05,  // 145:1046
  0x04, 0x20, 0x0A, 0x05,  // 146:1056
  0x04, 0x2A, 0x0A, 0x05,  // 147:1066
  0x04, 0x34, 0x0A, 0x05,  // 148:1076
  0x04, 0x3E, 0x0A, 0x05,  // 149:1086
  0x04, 0x48, 0x0A, 0x05,  // 150:1096
  0x04, 0x52, 0x0A, 0x05,  // 151:1106
  0x04, 0x5C, 0x0A, 0x05,  // 152:1116
  0x04, 0x66, 0x0A, 0x05,  // 153:1126
  0x04, 0x70, 0x0A, 0x05,  // 154:1136
  0x04, 0x7A, 0x0A, 0x05,  // 155:1146
  0x04, 0x84, 0x0A, 0x05,  // 156:1156
  0x04, 0x8E, 0x0A, 0x05,  // 157:1166
  0x04, 0x98, 0x0A, 0x05,  // 158:1176
  0x04, 0xA2, 0x0A, 0x05,  // 159:1186
  0xFF, 0xFF, 0x00, 0x03,  // 160:65535
  0x04, 0xAC, 0x04, 0x03,  // 161:1196
  0x04, 0xB0, 0x0A, 0x06,  // 162:1200
  0x04, 0xBA, 0x0A, 0x06,  // 163:1210
  0x04, 0xC4, 0x0C, 0x06,  // 164:1220
  0x04, 0xD0, 0x09, 0x06,  // 165:1232
  0x04, 0xD9, 0x04, 0x03,  // 166:1241
  0x04, 0xDD, 0x0A, 0x05,  // 167:1245
  0x04, 0xE7, 0x07, 0x05,  // 168:1255
  0x04, 0xEE, 0x0F, 0x09,  // 169:1262
  0x04, 0xFD, 0x07, 0x04,  // 170:1277
  0x05, 0x04, 0x09, 0x06,  // 171:1284
  0x05, 0x0D, 0x0D, 0x08,  // 172:1293
  0x05, 0x1A, 0x05, 0x03,  // 173:1306
  0x05, 0x1F, 0x0F, 0x09,  // 174:1311
  0x05, 0x2E, 0x07, 0x05,  // 175:1326
  0x05, 0x35, 0x07, 0x05,  // 176:1333
  0x05, 0x3C, 0x0C, 0x08,  // 177:1340
  0x05, 0x48, 0x07, 0x04,  // 178:1352
  0x05, 0x4F, 0x07, 0x04,  // 179:1359
  0x05, 0x56, 0x07, 0x05,  // 180:1366
  0x05, 0x5D, 0x0C, 0x06,  // 181:1373
  0x05, 0x69, 0x0A, 0x06,  // 182:1385
  0x05, 0x73, 0x03, 0x03,  // 183:1395
  0x05, 0x76, 0x06, 0x05,  // 184:1398
  0x05, 0x7C, 0x07, 0x04,  // 185:1404
  0x05, 0x83, 0x07, 0x04,  // 186:1411
  0x05, 0x8A, 0x09, 0x06,  // 187:1418
  0x05, 0x93, 0x11, 0x09,  // 188:1427
  0x05, 0xA4, 0x12, 0x09,  // 189:1444
  0x05, 0xB6, 0x11, 0x09,  // 190:1462
  0x05, 0xC7, 0x0A, 0x05,  // 191:1479
  0x05, 0xD1, 0x0C, 0x06,  // 192:1489
  0x05, 0xDD, 0x0C, 0x06,  // 193:1501
  0x05, 0xE9, 0x0C, 0x06,  // 194:1513
  0x05, 0xF5, 0x0C, 0x06,  // 195:1525
  0x06, 0x01, 0x0C, 0x06,  // 196:1537
  0x06, 0x0D, 0x0C, 0x06,  // 197:1549
  0x06, 0x19, 0x10, 0x09,  // 198:1561
  0x06, 0x29, 0x0C, 0x07,  // 199:1577
  0x06, 0x35, 0x0A, 0x06,  // 200:1589
  0x06, 0x3F, 0x0A, 0x06,  // 201:1599
  0x06, 0x49, 0x0A, 0x06,  // 202:1609
  0x06, 0x53, 0x0A, 0x06,  // 203:1619
  0x06, 0x5D, 0x05, 0x03,  // 204:1629
  0x06, 0x62, 0x04, 0x03,  // 205:1634
  0x06, 0x66, 0x05, 0x03,  // 206:1638
  0x06, 0x6B, 0x05, 0x03,  // 207:1643
  0x06, 0x70, 0x0B, 0x07,  // 208:1648
  0x06, 0x7B, 0x0C, 0x07,  // 209:1659
  0x06, 0x87, 0x0B, 0x07,  // 210:1671
  0x06, 0x92, 0x0B, 0x07,  // 211:1682
  0x06, 0x9D, 0x0B, 0x07,  // 212:1693
  0x06, 0xA8, 0x0B, 0x07,  // 213:1704
  0x06, 0xB3, 0x0B, 0x07,  // 214:1715
  0x06, 0xBE, 0x0C, 0x08,  // 215:1726
  0x06, 0xCA, 0x0B, 0x07,  // 216:1738
  0x06, 0xD5, 0x0B, 0x07,  // 217:1749
  0x06, 0xE0, 0x0B, 0x07,  // 218:1760
  0x06, 0xEB, 0x0B, 0x07,  // 219:1771
  0x06, 0xF6, 0x0B, 0x07,  // 220:1782
  0x07, 0x01, 0x09, 0x05,  // 221:1793
  0x07, 0x0A, 0x09, 0x06,  // 222:1802
  0x07, 0x13, 0x0A, 0x06,  // 223:1811
  0x07, 0x1D, 0x0A, 0x06,  // 224:1821
  0x07, 0x27, 0x0A, 0x06,  // 225:1831
  0x07, 0x31, 0x0A, 0x06,  // 226:1841
  0x07, 0x3B, 0x0A, 0x06,  // 227:1851
  0x07, 0x45, 0x0A, 0x06,  // 228:1861
  0x07, 0x4F, 0x0A, 0x06,  // 229:1871
  0x07, 0x59, 0x10, 0x09,  // 230:1881
  0x07, 0x69, 0x0A, 0x06,  // 231:1897
  0x07, 0x73, 0x0A, 0x06,  // 232:1907
  0x07, 0x7D, 0x0A, 0x06,  // 233:1917
  0x07, 0x87, 0x0A, 0x06,  // 234:1927
  0x07, 0x91, 0x0A, 0x06,  // 235:1937
  0x07, 0x9B, 0x04, 0x03,  // 236:1947
  0x07, 0x9F, 0x05, 0x03,  // 237:1951
  0x07, 0xA4, 0x05, 0x03,  // 238:1956
  0x07, 0xA9, 0x05, 0x03,  // 239:1961
  0x07, 0xAE, 0x09, 0x06,  // 240:1966
  0x07, 0xB7, 0x0A, 0x06,  // 241:1975
  0x07, 0xC1, 0x09, 0x06,  // 242:1985
  0x07, 0xCA, 0x09, 0x06,  // 243:1994
  0x07, 0xD3, 0x09, 0x06,  // 244:2003
  0x07, 0xDC, 0x09, 0x06,  // 245:2012
  0x07, 0xE5, 0x09, 0x06,  // 246:2021
  0x07, 0xEE, 0x0B, 0x08,  // 247:2030
  0x07, 0xF9, 0x09, 0x06,  // 248:2041
  0x08, 0x02, 0x0A, 0x06,  // 249:2050
  0x08, 0x0C, 0x0A, 0x06,  // 250:2060
  0x08, 0x16, 0x0A, 0x06,  // 251:2070
  0x08, 0x20, 0x0A, 0x06,  // 252:2080
  0x08, 0x2A, 0x09, 0x05,  // 253:2090
  0x08, 0x33, 0x09, 0x06,  // 254:2099
  0x08, 0x3C, 0x09, 0x05,  // 255:2108

  // Font Data:
  0x00,0x00,0x7C,0x01,  // 33
  0x00,0x00,0x0C,0x00,0x00,0x00,0x0C, // 34
  0x00,0x00,0x50,0x00,0xD0,0x01,0x7C,0x00,0xD0,0x01,0x7C,0x00,0x50, // 35
  0x30,0x01,0x28,0x01,0xFC,0x03,0x48,0x01,0xC8, // 36
  0x3C,0x00,0x24,0x00,0xBC,0x01,0x60,0x00,0x30,0x00,0xEC,0x01,0x20,0x01,0xE0,0x01,  // 37
  0x00,0x00,0xC0,0x00,0x38,0x01,0x24,0x01,0xC4,0x00,0x88,0x01,0x60,0x01,  // 38
  0x00,0x00,0x0C, // 39
  0x00,0x00,0xFC,0x00,0x02,0x01,  // 40
  0x00,0x00,0x86,0x01,0x78, // 41
  0x24,0x00,0x18,0x00,0x3C,0x00,0x18,0x00,0x24, // 42
  0x00,0x00,0x40,0x00,0x40,0x00,0xF0,0x01,0x40,0x00,0x40, // 43
  0x00,0x00,0x00,0x03,  // 44
  0x00,0x00,0x40,0x00,0x40, // 45
  0x00,0x00,0x00,0x01,  // 46
  0x80,0x01,0x70,0x00,0x0C, // 47
  0x00,0x00,0xF8,0x00,0x04,0x01,0x04,0x01,0xF8, // 48
  0x00,0x00,0x00,0x00,0x04,0x01,0xFC,0x01,0x00,0x01,  // 49
  0x00,0x00,0x88,0x01,0x44,0x01,0x24,0x01,0x18,0x01,  // 50
  0x00,0x00,0x08,0x01,0x24,0x01,0x24,0x01,0xD8, // 51
  0x00,0x00,0xC0,0x00,0xB0,0x00,0x88,0x00,0xFC,0x01,0x80, // 52
  0x00,0x00,0x3C,0x01,0x24,0x01,0x24,0x01,0xC4, // 53
  0x00,0x00,0xF8,0x00,0x2C,0x01,0x24,0x01,0xC4, // 54
  0x00,0x00,0x04,0x00,0x84,0x01,0x74,0x00,0x0C, // 55
  0x00,0x00,0xD8,0x00,0x24,0x01,0x24,0x01,0xD8, // 56
  0x00,0x00,0x38,0x01,0x24,0x01,0xA4,0x01,0xF8, // 57
  0x00,0x00,0x10,0x01,  // 58
  0x00,0x00,0x10,0x03,  // 59
  0x00,0x00,0x40,0x00,0x40,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0x10,0x01,  // 60
  0x00,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0, // 61
  0x00,0x00,0x10,0x01,0xA0,0x00,0xA0,0x00,0xA0,0x00,0x40,0x00,0x40, // 62
  0x00,0x00,0x04,0x00,0x64,0x01,0x14,0x00,0x0C, // 63
  0x00,0x00,0xF0,0x00,0x08,0x01,0x64,0x02,0x94,0x02,0x94,0x02,0xF4,0x01,0x88,0x00,0x70, // 64
  0x80,0x01,0x70,0x00,0x4C,0x00,0x4C,0x00,0x70,0x00,0x80,0x01,  // 65
  0x00,0x00,0xFC,0x01,0x24,0x01,0x24,0x01,0x24,0x01,0xD8, // 66
  0x00,0x00,0xF8,0x00,0x8C,0x01,0x04,0x01,0x04,0x01,0x08,0x01,  // 67
  0x00,0x00,0xFC,0x01,0x04,0x01,0x04,0x01,0x8C,0x01,0xF8, // 68
  0x00,0x00,0xFC,0x01,0x24,0x01,0x24,0x01,0x24,0x01,  // 69
  0x00,0x00,0xFC,0x01,0x24,0x00,0x24,0x00,0x24, // 70
  0x00,0x00,0xF8,0x00,0x8C,0x01,0x04,0x01,0x24,0x01,0xE8, // 71
  0x00,0x00,0xFC,0x01,0x20,0x00,0x20,0x00,0x20,0x00,0xFC,0x01,  // 72
  0x00,0x00,0xFC,0x01,  // 73
  0x00,0x04,0xFC,0x03,  // 74
  0x00,0x00,0xFC,0x01,0x20,0x00,0x50,0x00,0x88,0x00,0x04,0x01,  // 75
  0x00,0x00,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,  // 76
  0x00,0x00,0xFC,0x01,0x18,0x00,0x60,0x00,0x60,0x00,0x18,0x00,0xFC,0x01,  // 77
  0x00,0x00,0xFC,0x01,0x18,0x00,0x20,0x00,0xC0,0x00,0xFC,0x01,  // 78
  0x00,0x00,0xF8,0x00,0x8C,0x01,0x04,0x01,0x8C,0x01,0xF8, // 79
  0x00,0x00,0xFC,0x01,0x24,0x00,0x24,0x00,0x18, // 80
  0x00,0x00,0xF8,0x00,0x8C,0x01,0x04,0x01,0x8C,0x03,0xF8, // 81
  0x00,0x00,0xFC,0x01,0x24,0x00,0x64,0x00,0x9C,0x00,0x00,0x01,  // 82
  0x00,0x00,0x98,0x00,0x24,0x01,0x24,0x01,0x24,0x01,0xC8, // 83
  0x04,0x00,0x04,0x00,0xFC,0x01,0x04,0x00,0x04, // 84
  0x00,0x00,0xFC,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0xFC, // 85
  0x0C,0x00,0x70,0x00,0x80,0x01,0x80,0x01,0x70,0x00,0x0C, // 86
  0x0C,0x00,0x70,0x00,0xC0,0x01,0x3C,0x00,0xC0,0x01,0x70,0x00,0x0C, // 87
  0x04,0x01,0x8C,0x00,0x70,0x00,0x70,0x00,0x8C,0x01,0x04,0x01,  // 88
  0x04,0x00,0x18,0x00,0xE0,0x01,0x18,0x00,0x04, // 89
  0x84,0x01,0x44,0x01,0x24,0x01,0x14,0x01,0x0C,0x01,  // 90
  0x00,0x00,0xFC,0x03,0x04,0x02,  // 91
  0x0C,0x00,0x70,0x00,0x80,0x01,  // 92
  0x00,0x00,0x04,0x02,0xFC,0x03,  // 93
  0x00,0x00,0x00,0x00,0x08,0x00,0x04,0x00,0x04,0x00,0x08, // 94
  0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,  // 95
  0x00,0x00,0x02,0x00,0x04, // 96
  0x00,0x00,0xC0,0x01,0x50,0x01,0x50,0x01,0xF0,0x01,  // 97
  0x00,0x00,0xFE,0x01,0x10,0x01,0x10,0x01,0xE0, // 98
  0x00,0x00,0xE0,0x00,0x10,0x01,0x10,0x01,0x10,0x01,  // 99
  0x00,0x00,0xE0,0x00,0x10,0x01,0x10,0x01,0xFE,0x01,  // 100
  0x00,0x00,0xE0,0x00,0x50,0x01,0x50,0x01,0x60,0x01,  // 101
  0x10,0x00,0xFE,0x01,0x12, // 102
  0x00,0x00,0xE0,0x00,0x10,0x05,0x10,0x05,0xF0,0x03,  // 103
  0x00,0x00,0xFE,0x01,0x10,0x00,0x10,0x00,0xF0,0x01,  // 104
  0x00,0x00,0xF4,0x01,  // 105
  0x00,0x04,0xF4,0x07,  // 106
  0x00,0x00,0xFE,0x01,0x40,0x00,0xA0,0x00,0x10,0x01,  // 107
  0x00,0x00,0xFE,0x01,  // 108
  0x00,0x00,0xF0,0x01,0x10,0x00,0x10,0x00,0xF0,0x01,0x10,0x00,0x10,0x00,0xF0,0x01,  // 109
  0x00,0x00,0xF0,0x01,0x10,0x00,0x10,0x00,0xF0,0x01,  // 110
  0x00,0x00,0xE0,0x00,0x10,0x01,0x10,0x01,0xE0, // 111
  0x00,0x00,0xF0,0x07,0x10,0x01,0x10,0x01,0xE0, // 112
  0x00,0x00,0xE0,0x00,0x10,0x01,0x10,0x01,0xF0,0x07,  // 113
  0x00,0x00,0xF0,0x01,0x10,0x00,0x10, // 114
  0x00,0x00,0x30,0x01,0x50,0x01,0xD0,0x01,  // 115
  0x10,0x00,0xF8,0x01,0x10,0x01,0x10,0x01,  // 116
  0x00,0x00,0xF0,0x01,0x00,0x01,0x00,0x01,0xF0,0x01,  // 117
  0x30,0x00,0xC0,0x00,0x00,0x01,0xC0,0x00,0x30, // 118
  0x70,0x00,0x80,0x01,0x60,0x00,0x10,0x00,0x60,0x00,0x80,0x01,0x70, // 119
  0x10,0x01,0xA0,0x00,0x40,0x00,0xA0,0x00,0x10,0x01,  // 120
  0x30,0x04,0xC0,0x04,0x00,0x03,0xC0,0x00,0x30, // 121
  0x00,0x00,0x10,0x01,0x90,0x01,0x50,0x01,0x30,0x01,  // 122
  0x00,0x00,0x20,0x00,0xDC,0x03,0x04,0x02,  // 123
  0x00,0x00,0xFC,0x07,  // 124
  0x00,0x00,0x04,0x02,0xDC,0x03,0x20, // 125
  0x00,0x00,0x40,0x00,0x20,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x20, // 126
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 127
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 128
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 129
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 130
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 131
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 132
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 133
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 134
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 135
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 136
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 137
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 138
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 139
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 140
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 141
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 142
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 143
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 144
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 145
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 146
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 147
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 148
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 149
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 150
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 151
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 152
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 153
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 154
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 155
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 156
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 157
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 158
  0xF8,0x07,0x08,0x04,0x08,0x04,0x08,0x04,0xF8,0x07,  // 159
  0x00,0x00,0xD0,0x07,  // 161
  0x00,0x00,0xE0,0x00,0x10,0x01,0xF8,0x03,0x10,0x01,  // 162
  0x00,0x00,0x20,0x01,0xF8,0x01,0x24,0x01,0x24,0x01,  // 163
  0x08,0x01,0xF0,0x00,0x90,0x00,0x90,0x00,0xF0,0x00,0x08,0x01,  // 164
  0xA4,0x00,0xB8,0x00,0xE0,0x01,0xB8,0x00,0xA4, // 165
  0x00,0x00,0xB8,0x03,  // 166
  0x00,0x00,0x6C,0x02,0x54,0x02,0xB4,0x02,0x64,0x03,  // 167
  0x00,0x00,0x04,0x00,0x00,0x00,0x04, // 168
  0x00,0x00,0x70,0x00,0x88,0x00,0x74,0x01,0x54,0x01,0x54,0x01,0x88,0x00,0x70, // 169
  0x00,0x00,0xB0,0x00,0xB4,0x00,0xBC, // 170
  0x00,0x00,0x60,0x00,0xF0,0x00,0x60,0x00,0xF0, // 171
  0x00,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0xE0, // 172
  0x00,0x00,0x40,0x00,0x40, // 173
  0x00,0x00,0x70,0x00,0x88,0x00,0x74,0x01,0x34,0x01,0x74,0x01,0x88,0x00,0x70, // 174
  0x00,0x00,0x02,0x00,0x02,0x00,0x02, // 175
  0x00,0x00,0x1C,0x00,0x14,0x00,0x1C, // 176
  0x00,0x00,0x20,0x01,0x20,0x01,0xF8,0x01,0x20,0x01,0x20,0x01,  // 177
  0x00,0x00,0x24,0x00,0x34,0x00,0x2C, // 178
  0x00,0x00,0x24,0x00,0x34,0x00,0x2C, // 179
  0x00,0x00,0x00,0x00,0x04,0x00,0x02, // 180
  0x00,0x00,0xF0,0x07,0x00,0x01,0x00,0x01,0xF0,0x01,0x00,0x01,  // 181
  0x00,0x00,0x3C,0x00,0xFC,0x03,0x04,0x00,0xFC,0x03,  // 182
  0x00,0x00,0x20, // 183
  0x00,0x00,0x00,0x04,0x00,0x06,  // 184
  0x00,0x00,0x24,0x00,0x3C,0x00,0x20, // 185
  0x00,0x00,0xBC,0x00,0xA4,0x00,0xBC, // 186
  0x00,0x00,0xF0,0x00,0x60,0x00,0xF0,0x00,0x60, // 187
  0x00,0x00,0x24,0x00,0x3C,0x01,0xE0,0x00,0x70,0x00,0x18,0x00,0xC4,0x00,0xE0,0x01,0x80, // 188
  0x00,0x00,0x24,0x00,0x3C,0x01,0xE0,0x00,0x70,0x00,0x18,0x00,0x24,0x01,0xA0,0x01,0x60,0x01,  // 189
  0x00,0x00,0x24,0x00,0x34,0x01,0xEC,0x00,0x70,0x00,0x18,0x00,0xC4,0x00,0xE0,0x01,0x80, // 190
  0x00,0x00,0x00,0x06,0x00,0x05,0xD0,0x04,0x00,0x04,  // 191
  0x80,0x01,0x70,0x00,0x4C,0x00,0x4D,0x00,0x70,0x00,0x80,0x01,  // 192
  0x80,0x01,0x70,0x00,0x4D,0x00,0x4C,0x00,0x70,0x00,0x80,0x01,  // 193
  0x80,0x01,0x71,0x00,0x4C,0x00,0x4C,0x00,0x71,0x00,0x80,0x01,  // 194
  0x80,0x01,0x70,0x00,0x4D,0x00,0x4D,0x00,0x70,0x00,0x80,0x01,  // 195
  0x80,0x01,0x71,0x00,0x4C,0x00,0x4C,0x00,0x71,0x00,0x80,0x01,  // 196
  0x00,0x01,0xC0,0x00,0xBF,0x00,0xBB,0x00,0xC0,0x00,0x00,0x01,  // 197
  0x00,0x01,0xE0,0x00,0x98,0x00,0x84,0x00,0xFC,0x01,0x24,0x01,0x24,0x01,0x24,0x01,  // 198
  0x00,0x00,0xF8,0x00,0x8C,0x05,0x04,0x07,0x04,0x01,0x08,0x01,  // 199
  0x00,0x00,0xFC,0x01,0x24,0x01,0x25,0x01,0x24,0x01,  // 200
  0x00,0x00,0xFC,0x01,0x25,0x01,0x24,0x01,0x24,0x01,  // 201
  0x00,0x00,0xFD,0x01,0x24,0x01,0x25,0x01,0x24,0x01,  // 202
  0x00,0x00,0xFD,0x01,0x24,0x01,0x25,0x01,0x24,0x01,  // 203
  0x00,0x00,0xFC,0x01,0x01, // 204
  0x00,0x00,0xFD,0x01,  // 205
  0x01,0x00,0xFC,0x01,0x01, // 206
  0x01,0x00,0xFC,0x01,0x01, // 207
  0x20,0x00,0xFC,0x01,0x24,0x01,0x04,0x01,0x8C,0x01,0xF8, // 208
  0x00,0x00,0xFC,0x01,0x19,0x00,0x21,0x00,0xC1,0x00,0xFC,0x01,  // 209
  0x00,0x00,0xF8,0x00,0x8C,0x01,0x04,0x01,0x8D,0x01,0xF8, // 210
  0x00,0x00,0xF8,0x00,0x8C,0x01,0x05,0x01,0x8C,0x01,0xF8, // 211
  0x00,0x00,0xF8,0x00,0x8D,0x01,0x04,0x01,0x8D,0x01,0xF8, // 212
  0x00,0x00,0xF8,0x00,0x8D,0x01,0x05,0x01,0x8D,0x01,0xF8, // 213
  0x00,0x00,0xF8,0x00,0x8D,0x01,0x04,0x01,0x8D,0x01,0xF8, // 214
  0x00,0x00,0x10,0x01,0xA0,0x00,0x40,0x00,0xA0,0x00,0x10,0x01,  // 215
  0x00,0x00,0x78,0x01,0xCC,0x01,0x34,0x01,0x8C,0x01,0xF4, // 216
  0x00,0x00,0xFC,0x00,0x00,0x01,0x00,0x01,0x01,0x01,0xFC, // 217
  0x00,0x00,0xFC,0x00,0x00,0x01,0x01,0x01,0x00,0x01,0xFC, // 218
  0x00,0x00,0xFC,0x00,0x01,0x01,0x00,0x01,0x01,0x01,0xFC, // 219
  0x00,0x00,0xFC,0x00,0x01,0x01,0x00,0x01,0x01,0x01,0xFC, // 220
  0x04,0x00,0x18,0x00,0xE1,0x01,0x18,0x00,0x04, // 221
  0x00,0x00,0xFC,0x01,0x48,0x00,0x48,0x00,0x30, // 222
  0x00,0x00,0xFE,0x01,0x12,0x00,0x2A,0x01,0xC4,0x01,  // 223
  0x00,0x00,0xC2,0x01,0x54,0x01,0x50,0x01,0xF0,0x01,  // 224
  0x00,0x00,0xC0,0x01,0x54,0x01,0x52,0x01,0xF0,0x01,  // 225
  0x00,0x00,0xC0,0x01,0x56,0x01,0x54,0x01,0xF0,0x01,  // 226
  0x00,0x00,0xC6,0x01,0x52,0x01,0x54,0x01,0xF6,0x01,  // 227
  0x00,0x00,0xC4,0x01,0x50,0x01,0x50,0x01,0xF4,0x01,  // 228
  0x00,0x00,0xC0,0x01,0x57,0x01,0x55,0x01,0xF7,0x01,  // 229
  0x00,0x00,0xC0,0x01,0x50,0x01,0x50,0x01,0xE0,0x00,0x50,0x01,0x50,0x01,0x60,0x01,  // 230
  0x00,0x00,0xE0,0x00,0x10,0x05,0x10,0x07,0x10,0x01,  // 231
  0x00,0x00,0xE0,0x00,0x52,0x01,0x54,0x01,0x60,0x01,  // 232
  0x00,0x00,0xE0,0x00,0x50,0x01,0x54,0x01,0x62,0x01,  // 233
  0x00,0x00,0xE4,0x00,0x52,0x01,0x52,0x01,0x64,0x01,  // 234
  0x00,0x00,0xE0,0x00,0x54,0x01,0x50,0x01,0x64,0x01,  // 235
  0x02,0x00,0xF4,0x01,  // 236
  0x00,0x00,0xF4,0x01,0x02, // 237
  0x04,0x00,0xF2,0x01,0x04, // 238
  0x04,0x00,0xF0,0x01,0x04, // 239
  0x00,0x00,0xE0,0x00,0x14,0x01,0x1C,0x01,0xE0, // 240
  0x00,0x00,0xF6,0x01,0x12,0x00,0x14,0x00,0xF6,0x01,  // 241
  0x00,0x00,0xE0,0x00,0x12,0x01,0x14,0x01,0xE0, // 242
  0x00,0x00,0xE0,0x00,0x10,0x01,0x14,0x01,0xE2, // 243
  0x00,0x00,0xE0,0x00,0x16,0x01,0x14,0x01,0xE0, // 244
  0x00,0x00,0xE6,0x00,0x12,0x01,0x14,0x01,0xE6, // 245
  0x00,0x00,0xE4,0x00,0x10,0x01,0x10,0x01,0xE4, // 246
  0x00,0x00,0x40,0x00,0x40,0x00,0x50,0x01,0x40,0x00,0x40, // 247
  0x00,0x00,0xE0,0x01,0xD0,0x01,0x30,0x01,0xF0, // 248
  0x00,0x00,0xF0,0x01,0x02,0x01,0x04,0x01,0xF0,0x01,  // 249
  0x00,0x00,0xF0,0x01,0x00,0x01,0x04,0x01,0xF2,0x01,  // 250
  0x00,0x00,0xF0,0x01,0x06,0x01,0x04,0x01,0xF0,0x01,  // 251
  0x00,0x00,0xF4,0x01,0x00,0x01,0x00,0x01,0xF4,0x01,  // 252
  0x30,0x04,0xC0,0x04,0x04,0x03,0xC2,0x00,0x30, // 253
  0x00,0x00,0xFE,0x07,0x10,0x01,0x10,0x01,0xE0, // 254
  0x30,0x04,0xC4,0x04,0x00,0x03,0xC4,0x00,0x30  // 255
};
#endif
