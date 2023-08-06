#ifndef XOR_H
#define XOR_H

#include <stdlib.h>

void single_byte_xor(const unsigned char *input, size_t length, char* result, unsigned char key);
int contains_invalid_characters(const char *input);
void xor_buffers(unsigned char* buffer1, unsigned char* buffer2, unsigned char* result, size_t length);

#endif // !XOR_H
