#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vars_defs_functions.h"
#include "timer.h"
#include <pthread.h>

void *child_thread(void *args){
    int rank = (int)(long)args;
    int first = (ROWS / NUM_THREADS) * rank;
    int last = (ROWS / NUM_THREADS) * (rank + 1);
    int row, col, day, i, j;
    long thread_numS = 0;
    long thread_numZ = 0;
    long thread_numR = 0;
    long thread_numD = 0;
    int num_Zombie_Neighbours;
    int num_Susceptible_Neighbours;
    
    for(day=1; day <= TOTAL_DAYS; day++){
      thread_numS = 0;
      thread_numZ = 0;
      thread_numR = 0;
      thread_numD = 0;
      for(row=first; row<last; row++){
	for(col=0; col<COLS; col++){

	  //Check the State of the candidate cell, and act accordingly
	  switch(current[row][col].state){
	  case 'S':
	    num_Zombie_Neighbours = countZombieNeighbours(row, col, current);

		#if DEBUG_LEVEL > 1
	     	printf("main: Cell[%d][%d]: ", row, col);
       		printf("main: Num of Zombie Neighbours = %d\n", num_Zombie_Neighbours);
		#endif

		decide_S_to_ZorR(row, col, num_Zombie_Neighbours,	\
	     			&thread_numS, &thread_numZ, &thread_numR,			\
			       	current, future);
			

		//If Susceptible wasn't bitten in decide_S_to_ZorR()
	      	// => could possibly die naturally instead
       		if(current[row][col].stateChange == 'N'){
		#if DEBUG_LEVEL > 1
		printf("main: Susceptible wasn't bitten");
		#endif
	       		
       		     //decide_S_to_D(row, col, &thread_numS, &thread_numD, current, future);
	       	}
			
       		break;	

		
	  case 'Z':
		#if DEBUG_LEVEL > 1
	       	printf("main: Cell[%d][%d] is Zombie\n", row, col);
      		#endif

		//A Zombie might be defeated provided there are sufficient
	       	//number of Susceptible neighbours to do so, and then based
       		//on a defined probability
		num_Susceptible_Neighbours = countSusceptibleNeighbours(row, col, current);

	       	#if DEBUG_LEVEL > 1
       		printf("main: Cell[%d][%d]: ", row, col);
	       	printf("main: Num of Susceptible Neighbours = %d\n", num_Susceptible_Neighbours);
	       	#endif
			
       		if(num_Susceptible_Neighbours >= NUM_S_TO_DEFEAT_Z)
		  	decide_Z_to_D(row, col, num_Susceptible_Neighbours,	\
	       			&thread_numZ, &thread_numD,				\
       				current, future);

	       	break;

		
	  case 'R':
       		#if DEBUG_LEVEL > 1
	       	printf("main: Cell[%d][%d] is Removed\n", row, col);
       		#endif

	       	decide_R_to_Z(row, col, &thread_numR, &thread_numZ, current, future);
       		break;

		
	  case 'D':
	       	#if DEBUG_LEVEL > 1
       		printf("main: Cell[%d][%d] is Dead\n", row, col);
	       	#endif
			
       		decide_D_to_Empty(row, col, &thread_numD, current, future);
	       	break;
		
	  }
  	}
      }
      
      pthread_mutex_lock(&b_mutex);
      counter++;
      numS += thread_numS;
      numZ += thread_numZ;
      numR += thread_numR;
      numD += thread_numD;
      if(counter == NUM_THREADS){
	counter = 0;
	//Overwrite the current with the future, but only
      //overwrite the cells that have changed for efficiency
	for(i=0; i<ROWS; i++)
	  for(j=0; j<COLS; j++)
	    if(current[i][j].stateChange == 'Y')
	      current[i][j] = future[i][j];

	//Output numerical data to the daySZRD.dat file for the
        //day just completed.
       	outputDaySZRD(fp_daySZRD, day, numS, numZ, numR, numD);

       	//To save disk space, we can control how often world is
       	//output to a file. Useful if the world is large.
       	if(day%WORLD_OUTPUT_INTERVAL == 0){
       	  outputWorld(day, current);
	}
		
       	pthread_cond_broadcast(&cond);
       }
       else{
	 while(pthread_cond_wait(&cond, &b_mutex) != 0);
       }
       pthread_mutex_unlock(&b_mutex);
  }
    
  return NULL;
}
