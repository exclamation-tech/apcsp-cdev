//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};

/* createStudent dynamically creates a Student on the heap and adds that
   student to the student array
    - the firstName and lastName strings should be dynamically created
      based on the size of the fname and lname args */
void createStudent(char* fname, char* lname, int age, int id)
{
  //Dynamically creates a Student on the heap
  Student* student = (Student*)malloc(sizeof(Student));
  student->firstName = (char*)malloc((strlen(fname)+1)*sizeof(char));
  student->lastName = (char*)malloc((strlen(lname)+1)*sizeof(char));

  //Sets value of Student on heap
  strcpy(student->firstName, fname);
  strcpy(student->lastName, lname);
  student->age = age;
  student->id = id;

  //Adds that student to the student array, increments value
  students[numStudents] = student;
  numStudents++;
}

// free the memory associated with a student including the strings
void deleteStudent(Student* student)
{
  free(student->firstName);
  free(student->lastName);
  free(student);
}

/* iterate over the students array deleting every student and setting the pointer
   values to 0 and adjusting the numStudents to 0 */
void deleteStudents()
{
  //iterate over the students array deleting every student and setting the pointer values to 0
 for (int i = 0; i < numStudents; i++) {
   deleteStudent(students[i]);
  }

  //Adjust numStudents to 0
  numStudents=0;
}

 /* save all students in the student array to a file 'studentdata.txt' overwriting
    any existing file
     - the format of the file is one line per student as follows fname lname age id:
         tom thumb 15 1234
         james dean 21 2345
         katy jones 18 4532 */
void saveStudents(int key)
{
  //file pointer
  FILE* fp;

  //Opens the studentdata file with w+ mode
  fp = fopen(STUFILE, "w+");

  //defines the buffer
  char buff[1024];

  //checks for success
  if (fp) {
    //iterates over numStudents
    for(int i = 0; i < numStudents; i++) {

      //writes to file
      sprintf(buff, "%s %s %d %lu\n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);

      //Encrypts
      caesarEncrypt(buff, key);

      fprintf(fp, buff);

      //prints to user
      printf("saving: %s\n", buff);
    }

    //closes file
    fclose(fp);

    //lets the user know it's been saved
    printf("saved %d students\n", numStudents);
  }
}

// load the students from the data file overwriting all exisiting students in memory
void loadStudents(int key)
{
  //remove students from memory
  deleteStudents();

  //file pointer
  FILE* fp;

  //opens STUFILE on read mode
  fp = fopen(STUFILE, "r");

  //defines variables to read & create students
  char fname[256];
  char lname[256];
  unsigned int age;
  long id;

  //variable to track how many students made
  int studentsLoaded = 0;

  //buffer
  char buff[1024];

  //checks for success
  if(fp) {

    //infinite loop until broken
    while(1) {

      //gets buffer from file
      fgets(buff, 1024, fp);

      //decrypts buffer
      caesarDecrypt(buff, key);

      //scan for files & check the matches
      if(sscanf(buff, "%s %s %u %ld\n", fname, lname, &age, &id) == 4) {

        //creates the students with the loaded values
        createStudent(fname, lname, age, id);

        //Increases student loaded counter
        studentsLoaded++;
      } else {

        //breaks infinite loop, logs how many students loaded
        printf("loaded %d students\n", studentsLoaded);
        break;

      }
    }
  }
  fclose(fp);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id);
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}
