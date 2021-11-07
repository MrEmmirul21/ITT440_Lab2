#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> //needed for getppid() & getpid()
//This program to create multiple child
int main()
{
 for (int i=0; i<13; i++)
 {
  pid_t pid = fork();

  if (pid==0)
  {
   printf("%d. Child process => PPID=%d , PID=%d\n",i+1,getppid(),getpid());
   exit(0);
  }

  else
  {
   printf("Parent process => PID=%d\n",getpid());
   printf("Waiting for child process to finish...\n");
   wait(NULL);
   printf("child process finished.\n");
  }
 }
 return EXIT_SUCCESS;
 return 0;
}

