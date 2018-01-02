#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>//declares pid_t
#include<stdio.h> //declares fgets()
#include <stdlib.h>//delares exit
#include <string.h>






int main(void) {
    char command[20];
    char *parameters[]={command,NULL};
 
   int status;
   
 
    while (1){
       scanf("%s",&command); //make a string
       
   if(strcmp(command,"exit")!=0) {
	if(fork()==0){
           execve(command,NULL,0);
           break;
	}
	else {
	
		waitpid(-1,&status,0); //causes parent to wait
               
         }
      }
   else {
   exit(0);

}
   

}
 return;
}



