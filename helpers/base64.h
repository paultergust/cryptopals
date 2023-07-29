#ifndef BASE64_H
#define BASE64_H

#include <stdlib.h>

char* base64Encode(const unsigned char* input, size_t length);
unsigned char* base64Decode(const char* input, size_t length);

#endif // !BASE64_H
