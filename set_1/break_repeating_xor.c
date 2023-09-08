#include <stdio.h>
#include <string.h>

// let KEYSIZE be the gessed number for key length (try 2..40)

int hamming_distance(unsigned char* buffer_one, unsigned char* buffer_two, int length){
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (buffer_one[i] != buffer_two[i]) {
      count++;
    }
  }
  return count;
}

int main(int argc, char *argv[]){
  if (argc < 2) {
    printf("Missing arguments: string 1 and string 2");
  }
  char* buffer_one = argv[1];
  char* buffer_two = argv[2];
  int len = strlen(buffer_one);
  int dist = hamming_distance(buffer_one, buffer_two, len);
  printf("%d \n", dist);
}

