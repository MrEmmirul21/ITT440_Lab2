#include <stdio.h>  //needed for printf()
#include <unistd.h>  //needed for fork() & getpid()
#include <stdlib.h>  //needed for exit()
#include <sys/wait.h>  //needed for wait()
//This program to identify parent & child process
int main()
{
 int pid; // process ID

 switch (pid = fork())
 {
  case 0:  // fork() returns 0 to the child
          printf("I'm the child process: pid=%d\n",getpid());
          break;

  default:  // fork() returns a pid to the parent
          wait(NULL);
          printf("I'm the parent process: pid=%d , child pid=%d\n",getpid(),pid);
          break;

  case -1:  // something went wrong
          perror("fork");
          exit(1);
 }

 exit(0);

 return 0;
}
