#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  if (argc != 3){
    fprintf(stderr, "usage: cp /path/to/file /path/to/destination\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "couldn't open file");
    return 1;
  }

  FILE *nf = fopen(argv[2], "a");

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    fputs(line, nf);
  }

  fclose(fp);
  fclose(nf);

  return 0;
}
