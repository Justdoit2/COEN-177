#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>//declares pid_t
#include<stdio.h> //declares fgets()



#define MAXP 8

void create(int N){

  
     int status;
 	if(N<8) {
                //pid=fork();
		if(fork()!=0)   {
		printf("I am the original process parent:%d\n",getpid());
                
                waitpid(-1,&status,0);

			
		}
                else {
		printf("child:%d\n parent:%d\n",getpid(),getppid());
		 create(N+1);
		return;

		}
	 
	}
	
}

int main(void){
  
   create(0);
}


