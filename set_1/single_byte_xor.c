#include <stddef.h>
#include <stdio.h>
#include <string.h>

void single_byte_xor(const unsigned char *input, size_t length, char* result, unsigned char key) {
  for(size_t i = 0; i < length; i++) {
    result[i] = input[i] ^ key;
  }
  result[length] = '\0';
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Missing hex input argument\n");
    return 1;
  }

  char* hex_input = argv[1];

  unsigned char encrypted_bytes[256];
  size_t input_length = strlen(hex_input) / 2;

  for (size_t i = 0; i < input_length; i++) {
    sscanf(hex_input + 2 * i, "%2hhx", &encrypted_bytes[i]);
  }

  char result[input_length];
  for (unsigned char key = 0; key <= 254; key++) {
    single_byte_xor(encrypted_bytes, input_length, result, key);
    printf("Key: 0x%02x -  %s\n", key, result);
  }
}
