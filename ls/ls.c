#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main (int argc, char *argv[]) {
  DIR *directory;
  struct dirent *entry;

  if (argc > 2) {
    fprintf(stderr, "%d\n", argc);
    fprintf(stderr, "usage: ls path/to/file\n");
    return 1;
  }

  char *p;
  char path[1024];
  if (argc == 1) {
    p = ".";
  } else {
    p = argv[1];
  }
  
  directory = opendir(p);
  if (directory == NULL) {
    fprintf(stderr, "unable to access file path\n");
    return 1;
  }

  while ((entry = readdir(directory)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  closedir(directory);

  return 0;
}
