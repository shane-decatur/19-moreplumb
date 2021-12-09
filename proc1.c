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

  mkfifo("mario",0644);
  mkfifo("luigi",0644);

  int pipe1;
  int pipe2;
  pipe1 = open("mario", O_WRONLY);
  pipe2 = open("luigi",O_RDONLY);
  char line[100];

  while (1){
    printf("input message: ");
    fgets(line, sizeof(line),stdin);
    write(pipe1,line,sizeof(line));

    read(pipe2,line,sizeof(line));
    printf("your message but loud: %s\n",line);
  }
  return 0;
}
