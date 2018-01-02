#include<stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 10
 /* Comments are for me to remember and understand */

int main(int argc, char ** argv) {

int num_pages=atoi(argv[1]); //take in an arg on terminal
   
int *pages=(int*)malloc(num_pages*sizeof(int)); //size of pointer , takes num of pages

char buffer[BUFFERSIZE]; //read into 
      int lines=0; int faults=0;
while(fgets(buffer,BUFFERSIZE,stdin)) { //need char array on left, buffersize for num of characters
         ++lines;
         if(!(isdigit((int)(buffer[0])))) {
                   continue;
                }
	int requestNum;
       
	sscanf(buffer,"%d",&requestNum); // get page number
        
	int foundIdx=-1;

	int i;
        for ( i=0; i<num_pages;++i) {
        	if(pages[i]==requestNum) {

                	foundIdx=i;

                    }//if statement

             
 } //for loop

        if(foundIdx==-1) {
            	printf("Page number %d caused a page fault\n", requestNum);
                   ++faults;
                pages[num_pages-1]=requestNum; //set far right to new number

                int i;
               
	        for (i=0; i<num_pages-1;++i) { 
  						
			pages[i]=pages[i+1];

                   }//inner for loop
               
		continue ; //restart back to while loop, skipping bottom
            
		 }//outer if statement
           
		  
        pages[num_pages-1]=pages[foundIdx]; //found page put in very back right
          
        int j;
          
        for (j=foundIdx;j<num_pages-1;++j) { //everything to right found shifts 1 to left
                    
        	pages[j]=pages[j+1];
          
        }//for loop
   
    } //while loop
    printf("Number of lines read is %d and number of page fault is %d\n",lines,faults);
  return 0;
}
