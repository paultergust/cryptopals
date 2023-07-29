#include "hex.h"
#include <stddef.h>
#include <stdio.h>

static int hex_digit_to_value(char hex_digit) {
  if (hex_digit >= '0' && hex_digit <= '9') {
    return hex_digit - '0';
  } else if (hex_digit >= 'A' && hex_digit <= 'F') {
    return hex_digit - 'A' + 10;
  } else if (hex_digit >= 'a' && hex_digit <= 'f') {
    return hex_digit - 'a' + 10;
  }
  return -1;
}

size_t hex_to_binary(const char* hex_input, size_t hex_length, unsigned char* binary_output, size_t bin_length) {
  if (hex_input == NULL || binary_output == NULL) {
    return 0;
  }

  size_t input_index = 0;
  size_t output_index = 0;

  while (input_index < hex_length && output_index < bin_length) {
    int hi_nibble = hex_digit_to_value(hex_input[input_index++]);
    int lo_nibble = hex_digit_to_value(hex_input[input_index++]);

    if (hi_nibble < 0 || lo_nibble < 0) {
      // invalid hex digit
      return 0;
    }

    binary_output[output_index++] = (hi_nibble << 4) | lo_nibble;
  }
  return output_index;
}

size_t binary_to_hex(const unsigned char* binary_input, size_t binary_length, char* hex_output, size_t hex_length) {
  if (binary_input == NULL || hex_output == NULL) {
    return 0;
  }

  size_t input_index = 0;
  size_t output_index = 0;

  while (input_index < binary_length && output_index + 2 <= hex_length) {
    unsigned char byte = binary_input[input_index++];
    hex_output[output_index++] = "0123456789ABCDEF"[byte >> 4];
    hex_output[output_index++] = "0123456789ABCDEF"[byte & 0x0F];
  }

  return output_index;
}
