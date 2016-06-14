#include "mycosVScos.h"

int main()
{
   float eps;
   eps = 1.0e-04;
   float xmin;
   xmin = 0.1;
   float xmax;
   xmax = 1.0;
   float xstep;
   xstep = 0.1;
   mycosVScos(xmin, xmax, xstep, eps);

   return 0;
}
