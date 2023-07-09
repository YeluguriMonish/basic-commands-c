#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: cat path/to/file");
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "can't open file");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
  }

  fclose(fp);
  return 0;
}
