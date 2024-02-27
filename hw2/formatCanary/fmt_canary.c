#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
//#include "asm.h"

#define BUFSIZE 48
#define FLAGSIZE 64

void win() {
  char buf[FLAGSIZE];
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("Flag File is Missing. Problem is Misconfigured, please contact an Admin if you are running this on the shell server.\n");
    exit(0);
  }

  fgets(buf,FLAGSIZE,f);
  printf(buf);
}

void vuln(){
  char buf[BUFSIZE];

  printf("Would you like to read the flag? (yes/no)\n");

  fgets(buf, sizeof(buf), stdin);

  if (strstr(buf, "no") != NULL) {
    printf("Okay, Exiting...\n");
    exit(1);
  }
  else if (strstr(buf, "yes") == NULL) {
    puts("Received Unknown Input:\n");
    exit(1);
  }
  printf(buf);
  gets(buf);

  puts("Please enter your string: ");
  gets(buf);

  printf("Okay, time to return... Fingers Crossed... Jumping to 0x%x\n", get_return_address());
}

int main(int argc, char **argv){

  setvbuf(stdout, NULL, _IONBF, 0);
  
  gid_t gid = getegid();
  setresgid(gid, gid, gid);

  vuln();
  return 0;
}