#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers/xor.h"

void single_byte_xor(char *hex_input) {

  unsigned char encrypted_bytes[256];
  size_t input_length = strlen(hex_input) / 2;

  for (size_t i = 0; i < input_length; i++) {
    sscanf(hex_input + 2 * i, "%2hhx", &encrypted_bytes[i]);
  }

  char result[input_length];
  for (unsigned char key = 0; key <= 254; key++) {
    byte_xor(encrypted_bytes, input_length, result, key);
    if(!contains_invalid_characters(result)) {
      printf("Key: 0x%02x -  %s\n", key, result);
    }
  }
}
