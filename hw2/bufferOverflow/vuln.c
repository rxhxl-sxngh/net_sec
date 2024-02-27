#include <stdio.h>
#include <string.h>
#include <limits.h>

#define FLAGSIZE 128

void win() {
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  fgets(buf,FLAGSIZE,f);
  puts(buf);
  fflush(stdout);
}

void readbuf(char *buf, unsigned char len) {
   char *temp=buf;
   unsigned int i;
   char c;
   for (i=0; i<len; i++) {
      c = fgetc(stdin);
      *temp++=c;
      if (c=='\n') break;
   }
   while (c!='\n') {
      c = fgetc(stdin);
   }
}

#define ARRAY_SIZE 100

int insert_in_table(unsigned int *table, unsigned int pos, unsigned int value) {
   if (table+pos>=table+ARRAY_SIZE) {
      printf("Hacker detected!\n");
      return 0;
   }
   table[pos] = value;
   return 1;
}

unsigned int sizes[ARRAY_SIZE];
int main(int argc, char *argv[])
{
   unsigned int index;
   unsigned int value;
   int keepgoing=1;
   
   while (keepgoing) {
            printf("Enter a number?\n");
            scanf("%u",&value);
            fgetc(stdin);
            printf("Enter an index?\n");
            scanf("%u",&index);
            fgetc(stdin);
            keepgoing=insert_in_table(sizes,index,value);
   }
}
