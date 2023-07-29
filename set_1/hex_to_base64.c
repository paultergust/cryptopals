#include <openssl/types.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

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

char* base64Encode(const unsigned char *data, size_t dataLength) {
  BIO *bio, *b64;
  BUF_MEM *bufferPtr;

  b64 = BIO_new(BIO_f_base64());
  BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

  bio = BIO_new(BIO_s_mem());

  b64 = BIO_push(b64, bio);

  BIO_write(b64, data, dataLength);

  BIO_flush(b64);

  BIO_get_mem_ptr(b64, &bufferPtr);

  char *base64String = (char *)malloc(bufferPtr->length + 1);

  memcpy(base64String, bufferPtr->data, bufferPtr->length);

  base64String[bufferPtr->length] = '\0';

  BIO_free(b64);

  return base64String;
}


int main() {
  const char *hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
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
