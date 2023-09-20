#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers/hex.h"
#include "helpers/xor.h"


int fixed_xor(char* buffer_one, char* buffer_two) {
  size_t length = strlen(buffer_one);
  if (length != strlen(buffer_two)) {
    printf("Error: Both buffers must have the same length\n");
    return 1;
  }
    size_t binary_length = (length + 1) / 2; // Each byte is represented by 2 hexadecimal characters
    unsigned char buffer1[binary_length];
    unsigned char buffer2[binary_length];
    if (hex_to_binary(buffer_one, length, buffer1, binary_length) == 0 || hex_to_binary(buffer_two, length, buffer2, binary_length) == 0) {
        printf("Error: Invalid hexadecimal input.\n");
        return 1;
    }

  unsigned char result[binary_length];
  xor_buffers(buffer1, buffer2, result, length);

  char hex_result[length + 1];
  size_t hex_length = sizeof(hex_result);

  if (binary_to_hex(result, binary_length, hex_result, hex_length) == 0) {
    printf("Error: Unable to convert bin to hex\n");
    return 1;
  }

  printf("XOR Result: %s\n", hex_result);
  return 0;
}
