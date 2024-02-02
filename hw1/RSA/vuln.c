#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define FLAGSIZE 128
#define NUMTRANSACTIONS 10


void win() {
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  fgets(buf,FLAGSIZE,f);
  puts(buf);
  fflush(stdout);
}

int main(int argc, char *argv[])
{
   char bank[FLAGSIZE],amountstr[FLAGSIZE];
   FILE *f = fopen("bankamounts.txt","r");
   unsigned int amount;
   char bankguess[FLAGSIZE],amount_guess_str[FLAGSIZE];
   unsigned int amount_guess;
   unsigned int count=0;
   while (count<NUMTRANSACTIONS) {
      fgets(bank,FLAGSIZE,f);
      fgets(amountstr,FLAGSIZE,f);
      amount=atoi(amountstr);
      printf("What bank?\n");
      fgets(bankguess,FLAGSIZE,stdin);
      printf("What amount?\n");
      fgets(amount_guess_str,FLAGSIZE,stdin);
      amount_guess=atoi(amount_guess_str);
      if (amount!=amount_guess || strncmp(bankguess,bank,strlen(bank)-1)) {
         printf("Nice try!\n");
         exit(0);
      }
      count++;
   }
   printf("Wow! You got them all! Ok, here's the flag\n");
   win();
}