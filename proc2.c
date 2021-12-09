#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

int main(){

  int pipe1;
  int pipe2;
  pipe1 = open("mario",O_RDONLY);
  pipe2 = open("luigi",O_WRONLY);

  char line[100];

  while(1){

    read(pipe1,line,sizeof(line));

    int i = 0;
    for (i = 0; i < strlen(line); i++) {
				if (line[i] >= 97 && line[i] <= 122) line[i] -= 32;
		}
    write(pipe2,line,sizeof(line));
  }
  return 0;
}
