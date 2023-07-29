#ifndef BASE64_H
#define BASE64_H

#include <stdlib.h>

char* base64_encode(const unsigned char* input, size_t length);
unsigned char* base64_decode(const char* input, size_t length, size_t* output_length);

#endif // !BASE64_H
