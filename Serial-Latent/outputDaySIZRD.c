#include <stdio.h>
#include "vars_defs_functions.h"


void outputDaySIZRD(FILE *fp_daySZRD, int day,
		   unsigned long numS,
		   unsigned long numI,
		   unsigned long numZ,
		   unsigned long numR,
		   unsigned long numD){


  #if DEBUG_LEVEL > 0
  printf("outputDaySZRD: %d %ld %ld %ld %ld %ld\n", day, numS, numI, numZ, numR, numD);
  #endif

  fprintf(fp_daySZRD, "%d %ld %ld %ld %ld %ld\n", day, numS, numI, numZ, numR, numD);

}
