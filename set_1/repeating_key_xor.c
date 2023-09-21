#include <stdio.h>
#include <string.h>
#include "helpers/hex.h"

//In repeating-key XOR, you'll sequentially apply each byte of the key; the first byte of plaintext will be XOR'd against I, the next C, the next E, then I again for the 4th byte, and so on. 

void repeating_key_xor(const char* buffer, char* result, const char* key, char* output) {
  int key_length = strlen(key);
  for (int j = 0; j < strlen(buffer); j++)  {
    int i = j % key_length;
    result[j] = buffer[j] ^ key[i];
  }
  int length = strlen(buffer);
  char out[length*2];
  binary_to_hex((char*)result, strlen(result), out, length*2);
  output = out;
}
