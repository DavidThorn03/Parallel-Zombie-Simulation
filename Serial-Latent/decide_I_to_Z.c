#include <stdio.h>
#include <stdlib.h>
#include "vars_defs_functions.h"

void decide_I_to_Z(int row,
		   int col,
		   unsigned long *ptr_to_numI,
		   unsigned long *ptr_to_numZ,
		   CELL **current,
		   CELL **future){
  
  current[row][col].counter_I_to_Z--;
  
  if(current[row][col].counter_I_to_Z <= 0){
    //I turns: I -> Z
    future[row][col].state = 'Z';
    
    //This is used for updating current world with future world changes only
    current[row][col].stateChange = 'Y';
    
    #if DEBUG_LEVEL > 1
    printf("decide_I_to_Z: I -> Z\n\n");
    #endif

    //Increase number of Z by 1, and decrease number of I by 1
    (*ptr_to_numZ)++;
    (*ptr_to_numI)--;
  }
  else{
    #if DEBUG_LEVEL > 1
    printf("decide_I_to_Z: State stays as I\n\n");
    #endif
  }
}
