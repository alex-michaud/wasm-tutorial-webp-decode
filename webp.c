#include "emscripten.h"
#include <stdlib.h>
#include "src/webp/encode.h"
#include "src/webp/decode.h"

EMSCRIPTEN_KEEPALIVE
int encoder_version() {
  return WebPGetEncoderVersion();
}

EMSCRIPTEN_KEEPALIVE
int decoder_version() {
  return WebPGetDecoderVersion();
}

EMSCRIPTEN_KEEPALIVE
uint8_t* create_buffer(int width, int height) {
  return malloc(width * height * 4 * sizeof(uint8_t));
}

EMSCRIPTEN_KEEPALIVE
void destroy_buffer(uint8_t* p) {
  free(p);
}

int result[2];
EMSCRIPTEN_KEEPALIVE
void encode(uint8_t* img_in, int width, int height, float quality) {
  uint8_t* img_out;
  size_t size;

  size = WebPEncodeRGBA(img_in, width, height, width * 4, quality, &img_out);

  result[0] = (int)img_out;
  result[1] = size;
}

EMSCRIPTEN_KEEPALIVE
uint8_t* decode(uint8_t* data, size_t size, int* width, int* height) {
  uint8_t* buffer;
//  size_t size;

  buffer = WebPDecodeRGBA(data, size, width, height);

  return buffer;
}

EMSCRIPTEN_KEEPALIVE
int* get_info(const uint8_t* data, size_t size) {

  int* results = (int*) malloc(3 * sizeof(int));

  int width;
  int height;

  results[0] = WebPGetInfo(data, size, &width, &height);
  results[1] = width;
  results[2] = height;

  return results;
}

EMSCRIPTEN_KEEPALIVE
void free_result(uint8_t* result) {
  WebPFree(result);
}

EMSCRIPTEN_KEEPALIVE
int get_result_pointer() {
  return result[0];
}

EMSCRIPTEN_KEEPALIVE
int get_result_size() {
  return result[1];
}
