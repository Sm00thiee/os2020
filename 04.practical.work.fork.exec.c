#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  int n1 = fork();
  int n2 = fork();


  if(n1 > 0 && n2 == 0){
    char*args[] = {"free", "-h", NULL};
    execvp("free", args);
  }
  else if(n1 ==0 && n2 >0){
    char*args[] = {"ps", "-ef", NULL};
    execvp("ps", args);
  }
  return 0;
}
