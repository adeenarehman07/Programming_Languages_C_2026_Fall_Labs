/*
 * Name: Adeena
 * Surname: Rehman
 * Student ID: 251ADB241
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

int save_student(const Student* s, const char* filename) {
  if (s == NULL || filename == NULL) return -1;
  FILE* file = fopen(filename, "w");
  if (file == NULL) return -1;

  fprintf(file, "%s %d %.2f\n", s->name, s->age, s->gpa);
  fclose(file);
  return 0;
}

int load_student(const char* filename, Student* out) {
  if (filename == NULL || out == NULL) return -1;
  FILE* file = fopen(filename, "r");
  if (file == NULL) return -1;

  int items_read = fscanf(file, "%49s %d %f", out->name, &out->age, &out->gpa);
  fclose(file);

  if (items_read != 3) return -1;
  return 0;
}

int main(void) {
  const char* filename = "student.txt";
  Student original_student = {.name = "Alice", .age = 21, .gpa = 3.75};

  printf("Saving student to file...\n");
  if (save_student(&original_student, filename) != 0) {
    perror("Failed to save student");
    return EXIT_FAILURE;
  }

  Student loaded_student;
  memset(&loaded_student, 0, sizeof(Student));

  printf("Loading student from file...\n");
  if (load_student(filename, &loaded_student) != 0) {
    perror("Failed to load student");
    return EXIT_FAILURE;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded_student.name,
         loaded_student.age, loaded_student.gpa);

  return EXIT_SUCCESS;
}