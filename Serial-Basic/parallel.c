#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vars_defs_functions.h"
#include "timer.h"
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mymutex;
sem_t count_sem;
sem_t barrier_sem;
char **currDay;
char **nextDay;
unsigned long numS = ROWS * COLS - 1;
unsigned long numZ = 1;
unsigned long numR = 0;
unsigned long numD = 0;
int counter = 0;
FILE *fp_daySZRD;


int main(){

  double start, finish, elapsed;

  GET_TIME(start);

  
  int day = 0; //Current day
  int i, j, threads; //Variables for for-loops

  //Avoid possibility of stack overflow by dynamically declaring memory for the
  //current and future worlds. We need to 'free' this memory at the end of main()
  CELL **current;
  CELL **future;

  pthread_t *pthread_handles = malloc(NUM_THREADS * sizeof(pthread_t));
  pthread_mutex_init(&mymutex, NULL);
  sem_init(&barrier_sem, 0, 0);
  sem_init(&count_sem, 0, 1);
 
  current = (CELL**)malloc(ROWS*sizeof(CELL*));
  future = (CELL**)malloc(ROWS*sizeof(CELL*));
  
  for(i=0; i<ROWS; i++){
    current[i] = (CELL*)malloc(COLS*sizeof(CELL));
    future[i] = (CELL*)malloc(COLS*sizeof(CELL));
  }

  //File handle for daySZRD.dat
  FILE *fp_daySZRD;

  //Open daySZRD.dat for writing. We will need to close it at the end of main()
  fp_daySZRD = fopen("data/daySZRD.dat", "w");

  //Generate random seed so that we get different random numbers
  //each time the program is run
  srand((unsigned int)time(NULL));
  
  initialiseWorld(current, future, &numS, &numZ);

  //Output numerical data to a single file
  outputDaySZRD(fp_daySZRD, day, numS, numZ, numR, numD);

  //In this function, we create a separate file for each day,
  //indexed by the day. Then, we write the 2-dim world to that file.
  outputWorld(day, current);

  //We can control the level of printing to the console, using the
  //DEBUG_LEVEL macro definition (defined in vars_defs_functions.h)
  //Note how we always name the function running the printf() statement
  #if DEBUG_LEVEL > 1
  printf("main: numS = %ld, numI = %ld\n\n", numS, numI);
  #endif

  for (threads = 0; threads < NUM_THREADS; threads++) {
    pthread_create(&pthread_handles[threads], NULL, child_thread, (void *)(long)threads);
  }

  for (threads = 0; threads < NUM_THREADS; threads++) {
    pthread_join(pthread_handles[threads], NULL);
  }

  //Close our daySZRD.dat file
  fclose(fp_daySZRD);

  //Free memory which was allocated with malloc()
  free(current);
  free(future);
  free(pthread_handles);
  
  pthread_mutex_destroy(&mymutex);
  sem_destroy(&count_sem);
  sem_destroy(&barrier_sem);

  //Calculate the duration of our program and output to console
  GET_TIME(finish);
  elapsed = finish - start;
  printf("main: Time taken = %lf seconds\n", elapsed);
  
  return 0;
}
