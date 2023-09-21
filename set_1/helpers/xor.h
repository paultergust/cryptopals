#ifndef XOR_H
#define XOR_H

#include <stdlib.h>

void byte_xor(const char *input, size_t length, char* result, char key);
int contains_invalid_characters(const char *input);
void xor_buffers(char* buffer1, char* buffer2, char* result, size_t length);

#endif // !XOR_H
