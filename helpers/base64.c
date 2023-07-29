#include "base64.h"
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdlib.h>
#include <string.h>

char* base64_encode(const unsigned char* input, size_t length) {
  BIO *bio, *b64;
  BUF_MEM *bufferPtr;

  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new(BIO_s_mem());
  b64 = BIO_push(b64, bio);
  BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

  BIO_write(bio, input, length);
  BIO_flush(bio);
  BIO_get_mem_ptr(b64, &bufferPtr);

  char* output = (char *)malloc(bufferPtr->length + 1);
  memcpy(output, bufferPtr->data, bufferPtr->length);
  output[bufferPtr->length] = '\0';

  BIO_free_all(bio);

  return output;
}

unsigned char* base64_decode(const char* input, size_t length, size_t* output_length) {
  BIO *bio, *b64;

  unsigned char* buffer = (unsigned char*)malloc(length);
  *output_length = 0;

  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new_mem_buf(input, length);
  bio = BIO_push(b64, bio);
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

  *output_length = BIO_read(bio, buffer, length);
  BIO_free_all(bio);

  return buffer;
}
