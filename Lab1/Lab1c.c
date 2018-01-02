#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


void twelveChild(){
  
 //fork creates child process
 //getpid gets parent id 
 int status;
 int i;
 int level=1;
 int maxChild=3;
 for ( i = 0; i<maxChild;++i){
   if (fork()==0){
      level++;//increment level to go down the tree
     printf("Child:%d Parentt:%d\n",getpid(),getppid());
   
     i=-1;//reset the for loop
   }
   else {
     wait(NULL);//wait if parent
   }
   
   if(level==maxChild){
     exit(0);//stops creating while get to third level
   }
 }
}


int main(){
  twelveChild();
  //Creates 12 child processes, with each child creating another 3 
}
