#include <stdlib.h> //needed to define exit()
#include <unistd.h> //needed for fork() & getpid()
#include <stdio.h> //needed for printf()
#include <sys/wait.h> //needed for wait()

int main()
{
 int pid; /* process ID

 Note:
 fork() will return:
 <0 - error
 =0 - child process
 >0 - parent process  */

 switch (pid = fork())
 {
  case 0:  // fork() returns 0 to the child 
         printf("I am the child process: pid=%d \n ",getpid());
         break;

  default: // fork() returns a pid to the parent
         wait(NULL);
         printf("I am the parent process: \n parent pid=%d child pid=%d \n ",getpid(),pid);
         break;

  case 1: // something went wrong 
         perror("fork");
         exit(1);
 }
 exit(0);

 return 0;
}
