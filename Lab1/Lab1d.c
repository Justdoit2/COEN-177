#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

//PRINT 17 child processes, with 2 to  child per parent
void seventeenChild(){
  

 //getpid gets parent id 
 int status;
 
 int i;
 int level=1;
 int maxChild=3;
 int count=0;
 int empty=0; int track=0;
 for ( i = 0; i<maxChild;++i){
   if (fork()==0){
      
     level++;
     printf("Child:%d Parentt:%d\n",getpid(),getppid());
     
       if(level==2 && i==2){
          int x=getpid()+1;
           printf("Child:%d Parentt:%d\n",x,getpid()); 
           
           printf("Child:%d Parentt:%d\n",x+1,getpid());
           exit(0);
       }
       
      
      if(level>=2){
        maxChild=2;
        
      }
      
      
      
       
     i=-1;
    
   }
   else {
     wait(NULL);
   }
   
   if(level==4){
     exit(0);
   }
   
 }
}


int main(){
  seventeenChild();                   
}

/*  HOW MY PROGRAM RUNS:
				
				          1 //Parent:
		2                 9              16
	3     6          10      13        17   18 //Stops at Level 3
4     5  7  8     11   12   14  15 //Stops at Level 4  




*/
