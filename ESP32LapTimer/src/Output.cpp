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
#include "Output.h"

#include "Comms.h"
#include "UDP.h"
#include "Serial.h"
#ifdef USE_BLUETOOTH
#include "Bluetooth.h"
#endif
#ifdef USE_TCP
#include "TCP.h"
#endif
#ifdef USE_WEBSOCKET_OUTPUT
#include "TimerWebServer.h"
#endif
#ifdef USE_LORA
#include "Lora.h"
#endif
#ifdef USE_WEBSOCKET_OUTPUT
#include "WebServer.h"
#endif

#include "HardwareConfig.h"
#include <freertos/semphr.h>

#define MAX_OUTPUT_BUFFER_SIZE 2000

static uint8_t output_buffer[MAX_OUTPUT_BUFFER_SIZE];
static int output_buffer_pos = 0; //Keep track of where we are in the Queue

static SemaphoreHandle_t queue_semaphore = NULL;

// TODO: define this somewhere else!
static output_t outputs[] = {
  {NULL, udp_init, udp_send_packet, udp_update, output_input_callback},
#ifdef USE_SERIAL_OUTPUT
  {NULL, serial_init, serial_send_packet, serial_update, output_input_callback},
#endif // USE_SERIAL_OUTPUT
#ifdef USE_BLUETOOTH
  {NULL, bluetooth_init, bluetooth_send_packet, bluetooth_update, output_input_callback},
#endif // USE_BLUETOOTH
#ifdef USE_TCP
  {NULL, tcp_init, tcp_send_packet, tcp_update, output_input_callback},
#endif // USE_TCP
#ifdef USE_WEBSOCKET_OUTPUT
  {NULL, NULL, send_websocket, read_websocket, output_input_callback},
#endif // USE_WEBSOCKET_OUTPUT
#ifdef USE_LORA
  {NULL, lora_init, lora_send_packet, lora_update, output_input_callback},
#endif // USE_LORA
#ifdef USE_WEBSOCKET_OUTPUT
  {NULL, NULL, send_websocket, read_websocket, output_input_callback},
#endif // USE_WEBSOCKET_OUTPUT
};

#define OUTPUT_SIZE (sizeof(outputs)/sizeof(outputs[0]))


bool IRAM_ATTR addToSendQueue(uint8_t item) {
  if(xSemaphoreTake(queue_semaphore, portMAX_DELAY)) {
    if(output_buffer_pos >= MAX_OUTPUT_BUFFER_SIZE) {
      xSemaphoreGive(queue_semaphore);
      return false;
    }
    output_buffer[output_buffer_pos++] = item;
    xSemaphoreGive(queue_semaphore);
    return true;
  }
  return false;
}

uint8_t IRAM_ATTR addToSendQueue(uint8_t * buff, uint32_t length) {
  for (int i = 0; i < length; ++i) {
    if(!addToSendQueue(buff[i])) {
      return i;
    }
  }
  return length;
}

void update_outputs() {
  // First update all inputs before sending new stuff
  for(int i = 0; i < OUTPUT_SIZE; ++i) {
    if(outputs[i].update){
      outputs[i].update(&outputs[i]);
    }
  }
  if(xSemaphoreTake(queue_semaphore, portMAX_DELAY)) {
    if(output_buffer_pos > 0) {
#ifdef OUTPUT_DEBUG
  Serial.println("Output packet: ");
  Serial.write(output_buffer, output_buffer_pos);
  Serial.println("######");
#endif
      // Send current buffer to all configured outputs
      for(int i = 0; i < OUTPUT_SIZE; ++i) {
        if(outputs[i].sendPacket) {
          outputs[i].sendPacket(&outputs[i], output_buffer, output_buffer_pos);
        }
      }
      output_buffer_pos = 0;
    }
    xSemaphoreGive(queue_semaphore);
  }
}

void init_outputs() {
  queue_semaphore = xSemaphoreCreateMutex();
  for(int i = 0; i < OUTPUT_SIZE; ++i) {
    if(outputs[i].init) {
      outputs[i].init(&outputs[i]);
    }
  }
}

void output_input_callback(uint8_t* buf, uint32_t size) {
#ifdef INPUT_DEBUG
  Serial.println("Input packet: ");
  Serial.write(buf, size);
  Serial.println("######");
#endif
  for(uint32_t i = 0; i < size; ++i) {
    if(buf[i] == '\n') {
      i += 1; // include \n
      uint8_t ControlPacket = buf[0];
      uint8_t NodeAddr = buf[1];
      handleSerialControlInput((char*)buf, ControlPacket, NodeAddr, i);
      // We move the buf pointer and adjust the size, so we can begin from i=0 again
      buf = buf + i;
      size -= i;
      i = 0;
    }
  }
}
