#include <stdio.h>
#include <string.h>
#include "../helpers/hex.h"

//In repeating-key XOR, you'll sequentially apply each byte of the key; the first byte of plaintext will be XOR'd against I, the next C, the next E, then I again for the 4th byte, and so on. 

void repeating_key_xor(const char* buffer, unsigned char* result, const char* key) {
  int key_length = strlen(key);
  for (int j = 0; j < strlen(buffer); j++)  {
    int i = j % key_length;
    result[j] = buffer[j] ^ key[i];
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Missing arguments: STR, KEY");
    return 1;
  }

  char* str = argv[1];
  char* key = argv[2];
  int length = strlen(str);
  char result[length];

  repeating_key_xor(str, result, key);
  //TODO convert the result back to hex
  char output[length*2];
  binary_to_hex(result, strlen(result), output, length*2);
  printf("%s \n", output);
  return 0;
}
