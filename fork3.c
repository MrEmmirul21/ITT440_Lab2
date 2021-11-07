#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
// This program to execute parent and child process task
void childTask()
{
 printf("Assalamu'alaikum, I'm his daughter\n");
}
void parentTask()
{
 printf("Wa'alaikumussalam and I'm her father\n");
}

int main()
{
 pid_t pid = fork();

 if (pid==0)
 {
  childTask();
  exit(EXIT_SUCCESS);
 }
 else if(pid > 0)
 {
  wait(NULL);
  parentTask();
 }
 else
 {
  printf("Unable to create child process.");
 }
 return EXIT_SUCCESS;

 return 0;
}
