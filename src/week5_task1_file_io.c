/*
 * Name: Adeena
 * Surname: Rehman
 * Student ID: 251ADB241
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  const char* filename = "data.txt";

  if (argc > 1) {
    filename = argv[1];
  }

  printf("Writing lines to %s...\n", filename);

  FILE* file_write = fopen(filename, "w");

  if (file_write == NULL) {
    perror("Error opening file for writing");
    return EXIT_FAILURE;
  }

  fprintf(file_write, "Hello, file I/O in C!\n");
  fprintf(file_write, "This is another line.\n");

  fclose(file_write);

  printf("Reading contents:\n");

  FILE* file_read = fopen(filename, "r");

  if (file_read == NULL) {
    perror("Error opening file for reading");
    return EXIT_FAILURE;
  }

  char buffer[256];
  int lines_count = 0;

  while (fgets(buffer, sizeof(buffer), file_read) != NULL) {
    printf("%s", buffer);
    lines_count++;
  }

  fclose(file_read);

  printf("Lines read: %d\n", lines_count);

  return EXIT_SUCCESS;
}