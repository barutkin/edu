#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

char *mkarr(unsigned char *N)
{
   unsigned char Nscan;
   printf("Введите количество элементов массива (1-%hhu): ", UCHAR_MAX);
   while (!(scanf("%hhu", &Nscan)))
   {
      getchar();
      printf("Ошибка: введите количество элементов массива еще раз (1-%hhu): ", UCHAR_MAX);
   }
   *N = Nscan;
   
   static unsigned char *A;
   A = (char *) malloc(*N * sizeof(unsigned char));

   srand(time(NULL));
   unsigned char i;
   for (i = 0; i < *N; i++)
   {
      A[i] = (rand() - rand()) % CHAR_MAX;
   }

   return A;
}
