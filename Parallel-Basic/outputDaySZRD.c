#include <stdio.h>
#include "vars_defs_functions.h"


void outputDaySZRD(FILE *fp_daySZRD, int day,
		   long numS,
		   long numZ,
		   long numR,
		   long numD){


  #if DEBUG_LEVEL > 0
  printf("outputDaySZRD: %d %ld %ld %ld %ld\n", day, numS, numZ, numR, numD);
  #endif

  fprintf(fp_daySZRD, "%d %ld %ld %ld %ld\n", day, numS, numZ, numR, numD);

}
