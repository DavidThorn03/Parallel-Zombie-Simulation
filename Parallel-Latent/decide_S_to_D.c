//
//This function decides whether a Susceptible cell dies: S -> D
//
#include <stdio.h>
#include <stdlib.h>
#include "vars_defs_functions.h"

void decide_S_to_D(int row,
		   int col,
		   long *ptr_to_numS,
		   long *ptr_to_numD,
		   CELL **current,
		   CELL **future){
  
  float chance;

  //Generate a random "chance" between 0.0 and 1.0
  chance = (float)rand() / (float)RAND_MAX;
  
  //Susceptible wasn't bitten => chance of dying naturally according to PROB_S_TO_D
  if(chance <= PROB_S_TO_D){
    //S dies: S -> D
    future[row][col].state = 'D';
    
    //This is used for updating current world with future world changes only
    current[row][col].stateChange = 'Y';
    
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_D: S -> D\n\n");
    #endif

    //Increase number of D by 1, and decrease number of S by 1
    (*ptr_to_numD)++;
    (*ptr_to_numS)--;
  }
  else{
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_D: State stays as S\n\n");
    #endif
  }
}
