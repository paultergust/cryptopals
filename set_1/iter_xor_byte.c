#include <stdio.h>
#include "../helpers/xor.h"

int main(int argc, char* argv[]){
  if (argc < 2) {
    printf("Missing argument: Filename");
    exit(EXIT_FAILURE);
  }
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  char* filename = argv[1];
  
  fp = fopen(filename, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  int counter = 1;
  while ((read = getline(&line, &len, fp)) != -1) {
    char result[len];
    printf("Hash number %d \n", counter++);
    for (unsigned char key = 0; key <= 254; key++) {
      single_byte_xor(line, len, result, key);
      if(!contains_invalid_characters(result)) {
        printf("Key: 0x%02x -  %s\n", key, result);
      }
    }
  }

  fclose(fp);
  if (line)
    free(line);
  exit(EXIT_SUCCESS);
}
