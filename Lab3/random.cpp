#include<iostream>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
/* Comments help me keep track and understand*/
int main(int argc, char**argv) {

  int num_pages=atoi(argv[1]);
  int pages[num_pages];

for ( int i =0; i<num_pages;++i) {

           pages[i]=-1; //intialize dummy

          }

char read[10]; int Pagenum;
 int track=0; int faults=0;
while(fgets(read,sizeof(read),stdin)) {
            ++track;
              if(!(isdigit((int)(read[0])))) {

                         continue;
               }

            sscanf(read,"%d",&Pagenum);
             
			int found=-1;
   
           for ( int i =0; i<num_pages;++i) {
              
				if(pages[i]== Pagenum) {
                     found=1;
                     break;
                  }//if statement bracket

                  }//for loop bracket
           
		   if(found==-1) //page fault 

            {
                  printf("Page number %d caused a page fault.\n",Pagenum);
                   ++faults;
                  int random=rand()% (num_pages);
                
                  pages[random]=Pagenum;
             }
          
     
}//while loop bracket
     printf("The number of lines is %d and the number of page faults is %d\n",track,faults);
return 0;
}
