#include<stdlib.h>
#include <stdio.h>

#define BUFFERSIZE 10
 /* Comments are for me to remember and understand */

int main(int argc, char ** argv) {

int num_pages=atoi(argv[1]);
   
int *pages=(int*)malloc(num_pages*sizeof(int)); 

char buffer[BUFFERSIZE]; 
      int lines=0; int faults=0;
while(fgets(buffer,BUFFERSIZE,stdin)) { 
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

                    }//if statement bracket

             
 } //loop bracket

        if(foundIdx==-1) {
            	printf("Page number %d caused a page fault\n", requestNum);
                   ++faults;
                pages[num_pages-1]=requestNum; 

                int i;
               
	        for (i=0; i<num_pages-1;++i) { 
  						
			pages[i]=pages[i+1];

                   }
               
		continue ; 
            
		 }
           
		  
        pages[num_pages-1]=pages[foundIdx]; 
          
        int j;
          
        for (j=foundIdx;j<num_pages-1;++j) { 
                    
        	pages[j]=pages[j+1];
          
        }
   
    } 
    printf("Number of lines read is %d and number of page fault is %d\n",lines,faults);
  return 0;
}
