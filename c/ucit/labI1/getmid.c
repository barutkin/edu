#include <stdio.h>
#include <stdlib.h>

unsigned char getmid(unsigned char N, char *A)
{
   int sumL;
   unsigned char i;
   unsigned char midi;
   int sumR;
   unsigned char j;
   unsigned char midj;

   printf("| ");
   for (i = 0; i < N; i++)
   {
      printf("%hhi ", A[i]);
   }
   printf("|\n");
   printf("Разделим массив на две части с минимальным модулем разности сумм элементов обоих частей:\n");

   sumL = A[0];
   sumR = A[N - 1];
   i = 1;
   j = N - 2;
   midi = i - 1;
   midj = j + 1;
   do
   {
      unsigned char k;
      for (k = 0; k <= midi; k++)
      {
         printf("%hhi ", A[k]);
      }
      printf("| ");
      for (k = midi + 1; k < midj; k++)
      {
         printf("%hhi ", A[k]);
      }
      printf("| ");
      for (k = midj; k < N; k++)
      {
         printf("%hhi ", A[k]);
      }
      printf("\n");

      int absDiffLRi;
      int absDiffLRj;
      absDiffLRi = abs(sumL + A[i] - sumR);
      absDiffLRj = abs(sumL - (sumR + A[j]));
      if (absDiffLRi > absDiffLRj)
      {
         sumR += A[j];
         midj--;
         j--;
      }
      if (absDiffLRi < absDiffLRj)
      {
         sumL += A[i];
         midi++;
         i++;
      }
      if (absDiffLRi == absDiffLRj)
      {
         sumL += A[i];
         sumR += A[j];
         midi++;
         midj--;
         i++;
         j--;
      }
   }
   while (i <= j);
   for (i = 0; i <= midi; i++)
   {
      printf("%hhi ", A[i]);
   }
   printf("| | ");
   for (i = midi + 1; i < N; i++)
   {
      printf("%hhi ", A[i]);
   }
   printf("\n\t%d\t||\t%d\n", sumL, sumR);
   printf("Номер граничащего слева элемента (начиная с 0): %hhu\n", midi);
   
   return midi;

}
