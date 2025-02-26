//
// Global Variables and Definitions
// All times are in days
// Probabilities must be between 0.0 and 1.0 inclusive
//
#include <stdio.h>
#include <pthread.h>

#ifndef VARS_AND_DEFS
#define VARS_AND_DEFS

//Controls level of printing to the console.
//Useful for debugging: if this is set to 0,
//then there will be lots of printing to console
#define DEBUG_LEVEL 1

#define ROWS 30
#define COLS 30
#define TOTAL_DAYS 20

//Frequency to output the world to file. For e.g.:
//value of 1, means every day. A value of 10, means
//output every 10th day
//Useful when we have a big world bu
#define WORLD_OUTPUT_INTERVAL 1

//Susceptible to Zombie/Removed Parameters for Basic Model
//Tweak these to see different behaviour
#define PROB_S_TO_IorR_1 0.90
#define PROB_S_TO_IorR_2 0.91
#define PROB_S_TO_IorR_3 0.92
#define PROB_S_TO_IorR_4 0.93
#define PROB_S_TO_IorR_5 0.94
#define PROB_S_TO_IorR_6 0.95
#define PROB_S_TO_IorR_7 0.96
#define PROB_S_TO_IorR_8 0.97

//Susceptible to Dead Parameters: Probability of death by
//natural causes: S -> D
#define PROB_S_TO_D 0.0001

//Death: Time for dead cell to become empty
#define TIME_D_TO_EMPTY 3

//Minimum number of Susceptibles needed to defeat a Zombie and
//probability of that happening if we have that minimum number of S
#define NUM_S_TO_DEFEAT_Z 3
#define PROB_Z_TO_D 0.1

//Parameters relating to S -> R and R State, and
//time parameters for R -> Z.
//Minimum number of Zombies needed to savage a Susceptible and
//turn it into a Removed (R) rather than a Zombie (Z).
//R States ultimately resurrect as Z.
#define MIN_NUM_ZOMBIE_TO_SAVAGE_S 6
#define MIN_TIME_R_TO_Z 1
#define MAX_TIME_R_TO_Z 3


//Birth: not used at the moment
#define PROB_NEW_S 0.01


//Cell Type-definition
typedef struct cell {
  char state;
  int counter_I_to_Z; //For Latent Infection: time spent as I
  int counter_R_to_Z; //Time spent as R, before R -> Z
  int counter_D_to_Empty; //Time spent as D before cell marked empty
  int age; //Age of a person. Not currently used
  char stateChange; //Used to mark that a cell has changed
} CELL;



// ****** FOR THE LATENT INFECTION MODEL ****** //

//Infected to Zombie Parameters: Each cell will have an initial time (as random
//number between Min and Max) before: I->Z 
#define MIN_TIME_I_TO_Z 1
#define MAX_TIME_I_TO_Z 5

//Infected to Removed (Dead) Parameters: Probability of death by natural causes: I -> R(D)
#define PROB_I_TO_R 0.01
#define PROB_I_TO_D 0.0002

//Parallel const and global variables
#define NUM_THREADS 5
extern pthread_mutex_t b_mutex;// for barrier 
extern pthread_cond_t cond;

extern FILE *fp_daySIZRD;
extern CELL **current;
extern CELL **future;
extern long numS;
extern long numI;
extern long numZ;
extern long numR;
extern long numD;

extern int counter;// for barrier


//Function Prototypes

void initialiseWorld(CELL **current,
		     CELL **future,
		     long *ptr_to_numS,
		     long *ptr_to_numZ);

void outputWorld(int day,
		 CELL **current);

void outputDaySIZRD(FILE *fp_daySZRD, int day,
		    long numS,
		    long numZ,
		    long numI,
		    long numR,
		    long numD);

int countZombieNeighbours(int row,
			    int col,
			    CELL **current);

int countSusceptibleNeighbours(int row,
			       int col,
			       CELL **current);

void decide_S_to_IorR(int row,
		      int col,
		      int num_Zombie_Neighbours,
		      long *ptr_to_numS,
		      long *ptr_to_numI,
		      long *ptr_to_numR,
		      CELL **current,
		      CELL **future);


void decide_S_to_D(int row,
		   int col,
		   long *ptr_to_numS,
		   long *ptr_to_numD,
		   CELL **current,
		   CELL **future);

void decide_I_to_D(int row,
		   int col,
		   long *ptr_to_numI,
		   long *ptr_to_numD,
		   CELL **current,
		   CELL **future);


void decide_Z_to_D(int row,
		   int col,
		   int num_Susceptible_Neighbours,
		   long *ptr_to_numZ,
		   long *ptr_to_numD,
		   CELL **current,
		   CELL **future);


void decide_R_to_Z(int row,
		   int col,
		   long *ptr_to_numR,
		   long *ptr_to_numZ,
		   CELL **current,
		   CELL **future);


void decide_D_to_Empty(int row,
		       int col,
		       long *ptr_to_numD,
		       CELL **current,
		       CELL **future);

void decide_I_to_Z(int row,
		   int col,
		   long *ptr_to_numI,
		   long *ptr_to_numZ,
		   CELL **current,
		   CELL **future);

void *child_thread(void *args);

#endif
