#include <stdio.h>
#include <string.h>


// student structure
struct Student {
  char firstName[256];
  char lastName[256];
  int age;
  int studentID;
};

// function that prints out one student
void printStudent(struct Student* student)
{
  printf("----- student ------\n");
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %d\n", student->studentID);
}

// does what it says it does ... prints out all students
void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++) {
    printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[256];
  char input[256];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q')
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("First name: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].firstName);

      printf("Last name: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].lastName);

      while(1){
        printf("Age: ");
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &(students[numStudents].age)) == 1) break;
        printf("Invalid input, make sure you're entering an integer\n");
      }

      while(1){
        printf("ID: ");
        fgets(input, 256, stdin);
        if(sscanf(input, "%d", &(students[numStudents].studentID)) == 1) break;
        printf("Invalid input, make sure you're entering an integer\n");
      }

      numStudents++;
    }
  }

  printf("\nGoodbye!\n");
}
