#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count(FILE *f) {
  int words;
  int character;
  char c;

  words = 0;
  while (!feof(f)) {
    while ((c = fgetc(f)) != EOF) {
      if (c == ' ' || c == '\n') {
        words++;
      }
    }
  }

  return words;
}

void *parse_file(char *filename) {
  FILE *fp;
  fp = fopen(filename, "r");

  int words = count(fp);
  printf("%d\n", words);

  fclose(fp);

  return NULL;
}

// this is a simple program to parse words on a provided text file using pthread.
// to run it, simply execute ./main [file1, file2, ...]
int main(int argc, char *argv[]) {
    if (argc < 2) {
      printf("Ao menos um arquivo deve ser passado como argumento!");
      return 1;
    }

    pthread_t t[argc-1];

    for (int i=1; i < argc; i++) { pthread_create(&t[i-1], NULL, (void *)parse_file, argv[i]); }
    for (int i=1; i < argc; i++) { pthread_join(t[i-1], NULL); }

    return 0;
}
