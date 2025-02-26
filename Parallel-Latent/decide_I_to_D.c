//
//This function decides whether a Infected cell dies: I -> D
//
#include <stdio.h>
#include <stdlib.h>
#include "vars_defs_functions.h"

void decide_I_to_D(int row,
		   int col,
		   long *ptr_to_numI,
		   long *ptr_to_numD,
		   CELL **current,
		   CELL **future){

  //Error checking: This function should have only been called if
  //the current state is 'I' AND the future state hasn't changed to Z
  //so that it is also 'I'.
  //Therefore, check to make sure these conditions are true.
  //Otherwise, end the program and print an error to the console
  if(current[row][col].state != 'I' || future[row][col].state != 'I'){
    printf("decide_I_to_D: Error: Function called when current State not I or\
	   when I -> Z already. Program terminated!\n\n");

    exit(-1);
  }
  
  float chance;

  //Generate a random "chance" between 0.0 and 1.0
  chance = (float)rand() / (float)RAND_MAX;
  
  //Infected wasn't bitten => chance of dying naturally according to PROB_I_TO_D
  if(chance <= PROB_I_TO_D){
    //I dies: I -> D
    future[row][col].state = 'D';
    
    //This is used for updating current world with future world changes only
    current[row][col].stateChange = 'Y';
    
    #if DEBUG_LEVEL > 1
    printf("decide_I_to_D: S -> D\n\n");
    #endif

    //Increase number of D by 1, and decrease number of I by 1
    (*ptr_to_numD)++;
    (*ptr_to_numI)--;
  }
  else{
    #if DEBUG_LEVEL > 1
    printf("decide_I_to_D: State stays as I\n\n");
    #endif
  }
}
