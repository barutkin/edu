#include <stdlib.h>
#include <stdio.h>

float mycos(float x, float eps)
{
   float cosn;
   cosn = 1.0;
   float cossum;
   cossum = cosn;
   int n;
   n = 1;

   while (cosn > eps || -cosn > eps)
   {
      cosn = cosn * (-1.0) * x * x / (2 * n - 1) / (2 * n);
      cossum += cosn;
      n++;
   }

   return cossum;
}
