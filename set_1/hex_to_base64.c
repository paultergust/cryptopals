#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers/base64.h"

int hex_string_to_binary(const char *hexString, unsigned char **binaryData, size_t *dataLength){
  int length = strlen(hexString);
  if (length % 2 != 0) {
    // Hex should have even length
    return 0;
  }

  *dataLength = length / 2;
  *binaryData = (unsigned char *)malloc(*dataLength);

  for (int i = 0; i < *dataLength; i++) {
    sscanf(&hexString[i*2], "%2hhx", &(*binaryData)[i]);
  }
  return 1;
}

int hex_to_base64(char* hexString, char* base64String) {
  unsigned char *binaryData;
  size_t dataLength;

  if (!hex_string_to_binary(hexString, &binaryData, &dataLength)) {
    return 0;
  }

  base64String = base64Encode(binaryData, dataLength);

  free(binaryData);
  return 1;
}
