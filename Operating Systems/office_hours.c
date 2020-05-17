// Name: Jerry Olds
// ID: 1001533643
// Class: CSE-3320-002
// Due Date: 10/17/2018

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <time.h>

/*** Constants that define parameters of the simulation ***/

#define MAX_SEATS 3        /* Number of seats in the professor's office */
#define professor_LIMIT 10 /* Number of students the professor can help before he needs a 
break */
#define MAX_STUDENTS 1000  /* Maximum number of students in the simulation */
#define CONSECUTIVE_STUDENTS_LIMIT 5 // Maximum amount of consecutive students from the same
                                     // class that can enter the office

#define CLASSA 0
#define CLASSB 1

/* TODO */
/* Add your synchronization variables here */
pthread_mutex_t students_lock; // Mutex to guard number of students entering
                               // & leaving office

int consecutive_A_students; // Keep track of how many students from class A
                            // have entered in consecutively

int consecutive_B_students; // Keep track of how many students from class B
                            // have entered in consecutively

int A_students_waiting; // Keep track of how many students from class A
                        // are waiting to have questions answered

int B_students_waiting; // Keep track of how many students from class B
                        // are waiting to have questions answered

int on_break; // Boolean variable to state whether the professor is on break or not

/* Basic information about simulation.  They are printed/checked at the end 
 * and in assert statements during execution.
 *
 * You are responsible for maintaining the integrity of these variables in the 
 * code that you develop. 
 */

static int students_in_office;   /* Total numbers of students currently in the office */
static int classa_inoffice;      /* Total numbers of students from class A currently in the 
office */
static int classb_inoffice;      /* Total numbers of students from class B in the office */
static int students_since_break = 0;


typedef struct 
{
  int arrival_time;  // time between the arrival of this student and the previous student
  int question_time; // time the student needs to spend with the professor
  int student_id;
} student_info;

/* Called at beginning of simulation.  
 * TODO: Create/initialize all synchronization
 * variables and other global variables that you add.
 */
 
static int initialize(student_info *si, char *filename) 
{
  students_in_office = 0;
  classa_inoffice = 0;
  classb_inoffice = 0;
  students_since_break = 0;

  /* Initialize your synchronization variables (and 
   * other variables you might use) here
   */

// Initalize mutex
    if(pthread_mutex_init(&students_lock, NULL) != 0)
    {
        printf("\nstudents_lock mutex init failed\n");
        return 1;
    }

// Initalize consecutive student variables
    consecutive_A_students = 0;
    consecutive_B_students = 0;

// Initalize students waiting variables
    A_students_waiting = 0;
    B_students_waiting = 0;

// Initalize on_break
    on_break = 0;

  /* Read in the data file and initialize the student array */
  FILE *fp;

  if((fp=fopen(filename, "r")) == NULL) 
  {
    printf("Cannot open input file %s for reading.\n", filename);
    exit(1);
  }

  int i = 0;
  while ( (fscanf(fp, "%d%d\n", &(si[i].arrival_time), &(si[i].question_time))!=EOF) && i < 
MAX_STUDENTS ) 
  {
    i++;
  }

 fclose(fp);
 return i;
}

/* Code executed by professor to simulate taking a break 
 * You do not need to add anything here.  
 */
static void take_break() 
{
  printf("The professor is taking a break now.\n");
  sleep(5);
  assert( students_in_office == 0 );
  students_since_break = 0;
}

/* Code for the professor thread. This is fully implemented except for synchronization
 * with the students.  See the comments within the function for details.
 */
void *professorthread(void *junk) 
{
  printf("The professor arrived and is starting his office hours\n");

  while (1) 
  {
  // Professor thread is constantly checking if 10 students have been served
  // to call the take_break function
      if(students_since_break == professor_LIMIT)
      {
          while(students_in_office != 0)
              sleep(1);
          on_break = 1;
          take_break();
          on_break = 0;
          printf("Professor is now back from break.\n");
      }
  }
  pthread_exit(NULL);
}


/* Code executed by a class A student to enter the office.
 * You have to implement this.  Do not delete the assert() statements,
 * but feel free to add your own.
 */
void classa_enter(student_info *s_info) 
{

  /* TODO */
  /* Request permission to enter the office.  You might also want to add  */
  /* synchronization for the simulations variables below                  */
  /*  YOUR CODE HERE.                                                     */ 

// Student from class A must wait if 5 consecutive students from class A 
// were served before him/her
    if(consecutive_A_students == CONSECUTIVE_STUDENTS_LIMIT && B_students_waiting > 0)
    {
    // Output message
      printf("%d consecutive students from class A have been served. Student %d from class A"
              " must wait\n", CONSECUTIVE_STUDENTS_LIMIT, s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      A_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class A must wait if professor is currently on break
    else if(on_break == 1)
    {
    // Output message
      printf("Professor is currently on break. Student %d from class A must wait.\n",
              s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      A_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class A must wait until after the professor's break
    else if(students_since_break == professor_LIMIT)
    {
    // Output message
      printf("Student %d from class A must wait until after the professor's break.\n",
              s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      A_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class A must wait if there are currently students from class B in office
    else if(classb_inoffice > 0)
    {
    // Output message
      printf("Students from class B currently in office. Student %d from class A must"
             " wait\n", s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      A_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class A must wait if there are the maximum amount of students in the office
    else if(students_in_office == MAX_SEATS)
    {
    // Output message
      printf("Maximum amount of students currently in office. Student %d from class A must"
              " wait.\n", s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      A_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Conditions that force the student to wait
    while((consecutive_A_students == CONSECUTIVE_STUDENTS_LIMIT && B_students_waiting > 0) 
         || students_since_break == professor_LIMIT || on_break == 1 || classb_inoffice > 0
         || students_in_office == MAX_SEATS)
    sleep(1);

  pthread_mutex_lock(&students_lock);
  if(A_students_waiting > 0)
      A_students_waiting -= 1;
  students_in_office += 1;
  classa_inoffice += 1;
  consecutive_A_students += 1;
  consecutive_B_students = 0;
  students_since_break += 1;
  pthread_mutex_unlock(&students_lock);

}

/* Code executed by a class B student to enter the office.
 * You have to implement this.  Do not delete the assert() statements,
 * but feel free to add your own.
 */
void classb_enter(student_info *s_info) 
{

  /* TODO */
  /* Request permission to enter the office.  You might also want to add  */
  /* synchronization for the simulations variables below                  */
  /*  YOUR CODE HERE.                                                     */ 

// Student from class B must wait if 5 consecutive students from class B
// were served before him/her
    if(consecutive_B_students == CONSECUTIVE_STUDENTS_LIMIT && A_students_waiting > 0)
    {
    // Output message
      printf("%d consecutive students from class B have been served. Student %d from class B"
              " must wait\n", CONSECUTIVE_STUDENTS_LIMIT, s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      B_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class B must wait if professor is currently on break
    else if(on_break == 1)
    {
    // Output message
      printf("Professor is currently on break. Student %d from class B must wait.\n",
              s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      B_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class B must wait until after the professor's break
    else if(students_since_break == professor_LIMIT)
    {
    // Output message
      printf("Student %d from class B must wait until after the professor's break.\n",
              s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      B_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class B must wait if there are currently students from class A in office
    else if(classa_inoffice > 0)
    {
    // Output message
      printf("Students from class A currently in office. Student %d from class B must"
             " wait\n", s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      B_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Student from class B must wait if there are the maximum amount of students in the office
    else if(students_in_office == MAX_SEATS)
    {
    // Output message
      printf("Maximum amount of students currently in office. Student %d from class B must"
              " wait.\n", s_info->student_id);

    // Increment the amount of students from class A waiting
      pthread_mutex_lock(&students_lock);
      B_students_waiting += 1;
      pthread_mutex_unlock(&students_lock);
    }

// Conditions that force the student to wait
    while((consecutive_B_students == CONSECUTIVE_STUDENTS_LIMIT && A_students_waiting > 0) 
         || students_since_break == professor_LIMIT || on_break == 1  
         || classa_inoffice > 0 || students_in_office == MAX_SEATS)
    sleep(1);

  pthread_mutex_lock(&students_lock);
  if(B_students_waiting > 0)
      B_students_waiting -= 1;
  students_in_office += 1;
  classb_inoffice += 1;
  consecutive_A_students = 0;
  consecutive_B_students +=1;
  students_since_break += 1;
  pthread_mutex_unlock(&students_lock);

}

/* Code executed by a student to simulate the time he spends in the office asking questions
 * You do not need to add anything here.  
 */
static void ask_questions(int t) 
{
  sleep(t);
}


/* Code executed by a class A student when leaving the office.
 * You need to implement this.  Do not delete the assert() statements,
 * but feel free to add as many of your own as you like.
 */
static void classa_leave() 
{
  pthread_mutex_lock(&students_lock);
  students_in_office -= 1;
  classa_inoffice -= 1;
  pthread_mutex_unlock(&students_lock);
}

/* Code executed by a class B student when leaving the office.
 * You need to implement this.  Do not delete the assert() statements,
 * but feel free to add as many of your own as you like.
 */
static void classb_leave() 
{
 
  pthread_mutex_lock(&students_lock);
  students_in_office -= 1;
  classb_inoffice -= 1;
  pthread_mutex_unlock(&students_lock);

}

/* Main code for class A student threads.  
 * You do not need to change anything here, but you can add
 * debug statements to help you during development/debugging.
 */
void* classa_student(void *si) 
{
  student_info *s_info = (student_info*)si;

  /* enter office */
  classa_enter(s_info);

  printf("Student %d from class A enters the office\n", s_info->student_id);

  assert(students_in_office <= MAX_SEATS && students_in_office >= 0);
  assert(classa_inoffice >= 0 && classa_inoffice <= MAX_SEATS);
  assert(classb_inoffice >= 0 && classb_inoffice <= MAX_SEATS);
  assert(classb_inoffice == 0 );
  
  /* ask questions  --- do not make changes to the 3 lines below*/
  printf("Student %d from class A starts asking questions for %d minutes\n", 
s_info->student_id, s_info->question_time);
  ask_questions(s_info->question_time);
  printf("Student %d from class A finishes asking questions and prepares to leave\n", 
s_info->student_id);

  /* leave office */
  classa_leave();  

  printf("Student %d from class A leaves the office\n", s_info->student_id);

  assert(students_in_office <= MAX_SEATS && students_in_office >= 0);
  assert(classb_inoffice >= 0 && classb_inoffice <= MAX_SEATS);
  assert(classa_inoffice >= 0 && classa_inoffice <= MAX_SEATS);

  pthread_exit(NULL);
}

/* Main code for class B student threads.
 * You do not need to change anything here, but you can add
 * debug statements to help you during development/debugging.
 */
void* classb_student(void *si) 
{
  student_info *s_info = (student_info*)si;

  /* enter office */
  classb_enter(s_info);

  printf("Student %d from class B enters the office\n", s_info->student_id);

  assert(students_in_office <= MAX_SEATS && students_in_office >= 0);
  assert(classb_inoffice >= 0 && classb_inoffice <= MAX_SEATS);
  assert(classa_inoffice >= 0 && classa_inoffice <= MAX_SEATS);
  assert(classa_inoffice == 0 );

  printf("Student %d from class B starts asking questions for %d minutes\n", 
s_info->student_id, s_info->question_time);
  ask_questions(s_info->question_time);
  printf("Student %d from class B finishes asking questions and prepares to leave\n", 
s_info->student_id);

  /* leave office */
  classb_leave();        

  printf("Student %d from class B leaves the office\n", s_info->student_id);

  assert(students_in_office <= MAX_SEATS && students_in_office >= 0);
  assert(classb_inoffice >= 0 && classb_inoffice <= MAX_SEATS);
  assert(classa_inoffice >= 0 && classa_inoffice <= MAX_SEATS);

  pthread_exit(NULL);
}

/* Main function sets up simulation and prints report
 * at the end.
 */
int main(int nargs, char **args) 
{
  int i;
  int result;
  int student_type;
  int num_students;
  void *status;
  pthread_t professor_tid;
  pthread_t student_tid[MAX_STUDENTS];
  student_info s_info[MAX_STUDENTS];

  if (nargs != 2) 
  {
    printf("Usage: officehour <name of inputfile>\n");
    return EINVAL;
  }

  num_students = initialize(s_info, args[1]);
  if (num_students > MAX_STUDENTS || num_students <= 0) 
  {
    printf("Error:  Bad number of student threads. "
           "Maybe there was a problem with your input file?\n");
    return 1;
  }

  printf("Starting officehour simulation with %d students ...\n",
    num_students);

  result = pthread_create(&professor_tid, NULL, professorthread, NULL);

  if (result) 
  {
    printf("officehour:  pthread_create failed for professor: %s\n", strerror(result));
    exit(1);
  }

  srand(time(0)); // Seed random number generator

  for (i=0; i < num_students; i++) 
  {

    s_info[i].student_id = i;
    sleep(s_info[i].arrival_time);
                
    student_type = random() % 2;

    if (student_type == CLASSA)
    {
      result = pthread_create(&student_tid[i], NULL, classa_student, (void *)&s_info[i]);
    }
    else // student_type == CLASSB
    {
      result = pthread_create(&student_tid[i], NULL, classb_student, (void *)&s_info[i]);
    }

    if (result) 
    {
      printf("officehour: thread_fork failed for student %d: %s\n", 
            i, strerror(result));
      exit(1);
    }
  }

  /* wait for all student threads to finish */
  for (i = 0; i < num_students; i++) 
  {
    pthread_join(student_tid[i], &status);
  }

  /* tell the professor to finish. */
  pthread_cancel(professor_tid);

  // Destroy mutex
  pthread_mutex_destroy(&students_lock);

  printf("Office hour simulation done.\n");

  return 0;
}
