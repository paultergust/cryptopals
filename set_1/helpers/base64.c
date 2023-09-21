#include "base64.h"
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char* base64Encode(const unsigned char* input, size_t length) {
  BIO *bio, *b64;
  BUF_MEM *bufferPtr;

  b64 = BIO_new(BIO_f_base64());
  BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

  bio = BIO_new(BIO_s_mem());

  b64 = BIO_push(b64, bio);

  BIO_write(b64, input, length);

  BIO_flush(b64);

  BIO_get_mem_ptr(b64, &bufferPtr);

  char *base64String = (char *)malloc(bufferPtr->length + 1);

  memcpy(base64String, bufferPtr->data, bufferPtr->length);

  base64String[bufferPtr->length] = '\0';

  BIO_free(b64);

  return base64String;
}

unsigned char* base64Decode(const char* input, size_t length) {
  BIO *bio, *b64;

  unsigned char* buffer = (unsigned char*)malloc(length);
  size_t *output_length = 0;

  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new_mem_buf(input, length);
  bio = BIO_push(b64, bio);
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

  *output_length = BIO_read(bio, buffer, length);
  BIO_free_all(bio);

  return buffer;
}
