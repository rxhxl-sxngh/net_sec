#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


void win() {
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("Flag File is Missing. Problem is Misconfigured, please contact an Admin if you are running this on the shell server.\n");
    exit(0);
  }

  printf("you don't really win because I won't tell you the flag!\n");
}

int main(int argc, char **argv){

  setvbuf(stdout, NULL, _IONBF, 0);

  win();

  // Drop privileges before calling bash, so you
  // can't read flag.txt
  gid_t gid = getgid();
  setresgid(gid, gid, gid);

  execl("/bin/bash","bash",NULL);
  return 0;
}