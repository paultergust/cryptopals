#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BYTESIZE 8

// let KEYSIZE be the gessed number for key length (try 2..40)
// take first KEYSIZE bytes, and second KEYSIZE bytes. hamming_distance them.
// normalize result by dividing by KEYSIZE
// the KEYSIZE with the smallest normalized hamming distance is probably the key.
// you could proceed perhaps with the smallest 2-3 KEYSIZE values. 
// Or take 4 KEYSIZE blocks instead of 2 and average the distances
// now that you probably know the KEYSIZE, break the cyphertext into blocks of KEYSIZE length
// now transpose the blocks: make  a block that is the first byte of every block, and a block that is the second byte of every block, and so on.
// solve each block as if it was a single character XOR, you already have the code to do this
// for each block, the single byte xor key that produces the best looking histogram is te repeating key xor key byte for that block. Put them together and you have the key.

void str_to_bin(const char* input, int* output);
int hamming_distance(char* buffer_one, char* buffer_two, int length);
int ham_and_norm(char* buffer_one, char* buffer_two, int length);
void iter_keysize();

int main(int argc, char *argv[]){
  //if (argc < 2) {
    //printf("Missing arguments: string 1 and string 2");
    //return 1;
  //}
  char* buffer_one = "wokka wokka!!!";
  char* buffer_two = "this is a test";
  int dist = hamming_distance(buffer_one, buffer_two, strlen(buffer_one));
  printf("%d\n", dist);
}

void str_to_bin(const char* input, int* output) {
  size_t length = strlen(input);
  for (size_t i = 0; i < length; i++) {
    char c = input[i];
    for (int j = (BYTESIZE - 1); j >= 0; j--) {
      output[(i * BYTESIZE) + (7 - j)] = (c & (1 << j)) ? 1 : 0;
    }
  }
}

int hamming_distance(char* buffer_one, char* buffer_two, int length){
  size_t bitlength = length * BYTESIZE;
  int bits_one[bitlength];
  int bits_two[bitlength];
  str_to_bin(buffer_one, bits_one);
  str_to_bin(buffer_two, bits_two);
  int count = 0;
  for (int i = 0; i < bitlength; i++) {
    count += bits_one[i] ^ bits_two[i];
  }
  return count;
}

int ham_and_norm(char* buffer_one, char* buffer_two, int length) {
  int dist = hamming_distance(buffer_one, buffer_two, length);
  return dist / length;
}

