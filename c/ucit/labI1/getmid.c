#include <stdio.h>

unsigned char getmid(unsigned char N, unsigned char *A)
{
   int sumL;
   int sumR;
   unsigned char i;
   unsigned char j;
   unsigned char mid;

   printf("Имеем массив [%hhu]:\n", N);
   for (i = 0; i < N; i++)
   {
      printf("%hhu ", A[i]);
   }
   printf("\n");
   printf("Разделим массив на две части с минимальной разностью сумм элементов:\n");

   sumL = 0;
   sumR = 0;
   i = 0;
   j = N - 1;
   do
   {
      if (sumL > sumR)
      {
         sumR += A[j];
         j--;
      }
      if (sumL < sumR)
      {
         sumL += A[i];
         mid = i;
         i++;
      }
      if (sumL == sumR)
      {
         sumL += A[i];
         sumR += A[j];
         mid = i;
         i++;
         j--;
      }
   }
   while (i < j);

   for (i = 0; i <= mid; i++)
   {
      printf("%hhu ", A[i]);
   }
   printf("\t|\t");
   for (i = mid + 1; i < N; i++)
   {
      printf("%hhu ", A[i]);
   }
   printf("\n");
   printf("\t%d\t|\t%d\n", sumL, sumR);
   printf("Номер граничащего слева элемента (начиная с 0): %hhu\n", mid);
   
   return mid;

}
