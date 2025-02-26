#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vars_defs_functions.h"
#include "timer.h"
#include <pthread.h>

pthread_mutex_t b_mutex;
pthread_cond_t cond;

CELL **current;
CELL **future;
long numS = 0;
long numI = 0;
long numZ = 0;
long numR = 0;
long numD = 0;
int counter = 0;
FILE *fp_daySIZRD;


int main(){

  double start, finish, elapsed;

  GET_TIME(start);

  
  int i, threads; //Variables for for-loops

  //Avoid possibility of stack overflow by dynamically declaring memory for the
  //current and future worlds. We need to 'free' this memory at the end of main()


  pthread_t *pthread_handles = malloc(NUM_THREADS * sizeof(pthread_t));
  pthread_mutex_init(&b_mutex, NULL);
  pthread_cond_init(&cond, NULL);

 
  current = (CELL**)malloc(ROWS*sizeof(CELL*));
  future = (CELL**)malloc(ROWS*sizeof(CELL*));
  
  for(i=0; i<ROWS; i++){
    current[i] = (CELL*)malloc(COLS*sizeof(CELL));
    future[i] = (CELL*)malloc(COLS*sizeof(CELL));
  }

  //Open daySIZRD.dat for writing. We will need to close it at the end of main()
  fp_daySIZRD = fopen("data/daySIZRD.dat", "w");

  //Generate random seed so that we get different random numbers
  //each time the program is run
  srand((unsigned int)time(NULL));
  
  initialiseWorld(current, future, &numS, &numZ);

  //Output numerical data to a single file
  outputDaySIZRD(fp_daySIZRD, 0, numS, numI, numZ, numR, numD);

  //In this function, we create a separate file for each day,
  //indexed by the day. Then, we write the 2-dim world to that file.
  outputWorld(0, current);

  //We can control the level of printing to the console, using the
  //DEBUG_LEVEL macro definition (defined in vars_defs_functions.h)
  //Note how we always name the function running the printf() statement
  #if DEBUG_LEVEL > 1
  printf("main: numS = %ld, numI = %ld\n\n", numS, numZ);
  #endif

  for (threads = 0; threads < NUM_THREADS; threads++) {
    pthread_create(&pthread_handles[threads], NULL, child_thread, (void *)(long)threads);
  }

  for (threads = 0; threads < NUM_THREADS; threads++) {
    pthread_join(pthread_handles[threads], NULL);
  }

  //Close our daySZRD.dat file
  fclose(fp_daySIZRD);


  for (i = 0; i < ROWS; i++) {
    free(current[i]);
    free(future[i]);
  }
  //Free memory which was allocated with malloc()
  free(current);
  free(future);
  free(pthread_handles);
  
  pthread_mutex_destroy(&b_mutex);
  pthread_cond_destroy(&cond);

  //Calculate the duration of our program and output to console
  GET_TIME(finish);
  elapsed = finish - start;
  printf("main: Time taken = %lf seconds\n", elapsed);
  
  return 0;
}
