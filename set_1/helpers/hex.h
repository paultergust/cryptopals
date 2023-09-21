#ifndef HEX_H
#define HEX_H

#include <stdlib.h>

size_t hex_to_binary(const char* hex_input, size_t hex_length, char* binary_output, size_t binary_length);
size_t binary_to_hex(const char* binary_input, size_t binary_length, char* hex_output, size_t hex_length);
#endif // !HEX_H
