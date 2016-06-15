#include <stdio.h>
#include <stdlib.h>

unsigned char getmid(unsigned char N, char *A)
{
   int sumL;
   unsigned char i;
   unsigned char mid;
   unsigned char midi;
   int sumR;
   unsigned char k;
   int absDiffLRi;
   int absDiffLRmin;

   for (i = 0; i < N; i++)
   {
      printf("%hhi ", A[i]);
   }
   printf("\nРазделим массив на две части с минимальным модулем разности сумм элементов обоих частей:\n");

   midi = 0;
   sumL = A[midi];
   sumR = 0;
   for (k = midi + 1; k < N; k++)
   {
      sumR += A[k];
   }   
   absDiffLRi = abs(sumL - sumR);
   absDiffLRmin = absDiffLRi;
   for (i = midi + 1; i < N; i++)
   {
      /*
      for (k = 0; k <= midi; k++)
      {
         printf("%hhi ", A[k]);
      }
      printf("| ");
      for (k = midi + 1; k < N; k++)
      {
         printf("%hhi ", A[k]);
      }
      printf("\n\t%d\t<->\t%d\t:\t%d\n", sumL, sumR, absDiffLRi);
      */

      midi = i;
      sumL += A[i];
      sumR -= A[i];
      absDiffLRi = abs(sumL - sumR);
      if (absDiffLRi < absDiffLRmin)
      {
         absDiffLRmin = absDiffLRi;
	 mid = midi; 
      }
   }
   sumL = 0;
   sumR = 0;
   for (i = 0; i <= mid; i++)
   {
      sumL += A[i]; 
      printf("%hhi ", A[i]);
   }
   printf("|| ");
   for (i = mid + 1; i < N; i++)
   {
      sumR += A[i];
      printf("%hhi ", A[i]);
   }
   printf("\n\t%d\t||\t%d\n", sumL, sumR);
   printf("Номер граничащего слева элемента (начиная с 0): %hhu\n", mid);
    
   return mid;

}
