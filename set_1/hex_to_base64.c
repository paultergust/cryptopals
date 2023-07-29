#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helpers/base64.h"

int hexStringToBinary(const char *hexString, unsigned char **binaryData, size_t *dataLength){
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

int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Missing hex string as argument\n");
    return 1;
  }
  const char *hexString = argv[1];
  unsigned char *binaryData;
  size_t dataLength;

  if (!hexStringToBinary(hexString, &binaryData, &dataLength)) {
    printf("Invalid hex string \n");
    return 1;
  }

  char *base64String = base64Encode(binaryData, dataLength);
  printf("Base64: %s\n", base64String);

  free(binaryData);
  free(base64String);
  return 0;
}
