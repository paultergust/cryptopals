#include "xor.h"

void single_byte_xor(const unsigned char *input, size_t length, char* result, unsigned char key) {
  for(size_t i = 0; i < length; i++) {
    result[i] = input[i] ^ key;
  }
  result[length] = '\0';
}

int contains_invalid_characters(const char *input) {
  // limit to 100 chars lest it runs for too long
  int limitCounter = 100;
  while (*input != '\0' && limitCounter > 0) {
    if (*input < 32 || *input > 126) {
      return 1;
    }
    limitCounter--;
  }
  return 0;
}

void xor_buffers(unsigned char* buffer1, unsigned char* buffer2, unsigned char* result, size_t length) {
  for (size_t i = 0; i < length; i++) {
    result[i] = buffer1[i] ^ buffer2[i];
  }
}
