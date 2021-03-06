#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "mycos.h"

int mycosVScos(float xmin, float xmax, float xstep, float eps)
{
   float x;

   printf("---------------------------\n");
   printf("|  x  | mycos(x) | cos(x) |\n");
   printf("---------------------------\n");
   for (x = xmin; x <= (xmax + FLT_EPSILON); x += xstep)
   {
      printf("| %1.1f |  %1.4f  | %1.4f |\n", x, mycos(x, eps), cos(x));
   }
   printf("---------------------------\n");

   return 0;
}
