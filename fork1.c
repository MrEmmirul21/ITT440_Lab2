#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//This program to use fork() system call
int main()
{
 fork();
 printf("This is fork system call.\n");

 return 0;
}
