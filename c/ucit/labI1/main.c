#include <stdlib.h>
#include "mkarr.h"
#include "getmid.h"

int main()
{
   unsigned char N;
   char *myA;

   myA = mkarr(&N);
   getmid(N, myA);
   
   free(myA);

   return 0;
}

