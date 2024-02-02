#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define FLAGSIZE 128

int main(int argc, char *argv[])
{
   srand(1706545804);
   unsigned int num;
   unsigned int inputnum, count=0;
   while (count<10) {
        num = random()%500;
        printf("%d\n", num);
        count++;
   }
}


