#include <stdio.h>
#include "vars_defs_functions.h"


void outputDaySIZRD(FILE *fp_daySZRD, int day,
		   long numS,
		   long numI,
		   long numZ,
		   long numR,
		   long numD){


  #if DEBUG_LEVEL > 0
  printf("outputDaySZRD: %d %ld %ld %ld %ld %ld\n", day, numS, numI, numZ, numR, numD);
  #endif

  fprintf(fp_daySIZRD, "%d %ld %ld %ld %ld %ld\n", day, numS, numI, numZ, numR, numD);

}
