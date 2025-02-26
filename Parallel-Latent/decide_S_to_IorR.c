//
//This function makes the decision as to whether a Susceptible is bitten and
//then changes it into a Iombie or Removed. This is based on the number of Iombie
//neighbours:
//  If there are 1 - 5 Iombie neighbours, do S -> I with defined probability
//  If there are 6 or more Iombie neighbours, do S -> R, with defined probability
//
#include <stdio.h>
#include <stdlib.h>
#include "vars_defs_functions.h"

void decide_S_to_IorR(int row,
		      int col,
		      int num_Zombie_Neighbours,
		      long *ptr_to_numS,
		      long *ptr_to_numI,
		      long *ptr_to_numR,
		      CELL **current,
		      CELL **future){

  float chance;
 
  switch(num_Zombie_Neighbours){

  case 0:
    //No Iombie neighbours => do nothing!
    
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: State stays as S\n\n");
    #endif

    break;

  case 1:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_1 = %f\n", PROB_S_TO_I_1);
    #endif

    if(chance <= PROB_S_TO_IorR_1){
      //Cell will change state. Either:
      //  S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
    
    break;

  case 2:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_2 = %f\n", PROB_S_TO_I_2);
    #endif

    if(chance <= PROB_S_TO_IorR_2){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
  
    break;

  case 3:

    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_3 = %f\n", PROB_S_TO_I_3);
    #endif

    if(chance <= PROB_S_TO_IorR_3){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
        
    break;   
  
  case 4:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_4 = %f\n", PROB_S_TO_I_4);
    #endif

    if(chance <= PROB_S_TO_IorR_4){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
   
    break;  

  case 5:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_5 = %f\n", PROB_S_TO_I_5);
    #endif

    if(chance <= PROB_S_TO_IorR_5){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
    
    break; 

  case 6:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_6 = %f\n", PROB_S_TO_I_6);
    #endif

    if(chance <= PROB_S_TO_IorR_6){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
    
    break;
    
  case 7:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_7 = %f\n", PROB_S_TO_I_7);
    #endif

    if(chance <= PROB_S_TO_IorR_7){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State 
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
   
    break;
   
  case 8:
    // Generate a random "chance" between 0.0 and 1.0
    chance = (float)rand() / (float)RAND_MAX;
  
    #if DEBUG_LEVEL > 1
    printf("decide_S_to_IorR: chance = %f\n", chance);
    printf("decide_S_to_IorR: PROB_S_TO_I_8 = %f\n", PROB_S_TO_I_8);
    #endif

    if(chance <= PROB_S_TO_IorR_8){
      //Cell will change state. Either:
      //S -> I or S -> R
      
      if(num_Zombie_Neighbours < MIN_NUM_ZOMBIE_TO_SAVAGE_S){
	//num_Zombie_Neighbours is BELOW minimum needed
	//to savage a Susceptible. So, here: S -> I
	
	future[row][col].state = 'I';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> I\n\n");
        #endif

	//Increase numI, decrease numS
	(*ptr_to_numI)++;
	(*ptr_to_numS)--;
      }
      else{
	//num_Zombie_Neighbours is at or above minimum
	//needed to savage a Susceptible. In this case,
	//it will be considered to be savaged, and:
	//  S -> R instead of S -> I.
	
	future[row][col].state = 'R';
	
        #if DEBUG_LEVEL > 1
	printf("decide_S_to_IorR: S -> R\n\n");
        #endif

	//Increase numR, decrease numS
	(*ptr_to_numR)++;
	(*ptr_to_numS)--;

      }
      //Mark Cell has having changed State 
      current[row][col].stateChange = 'Y';

    }
    else{
      #if DEBUG_LEVEL > 1
      printf("decide_S_to_IorR: State stays as S\n\n");
      #endif
    }
    break;
  }
}
