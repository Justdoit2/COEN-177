#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<deque>
#include<set>



using namespace std;

int main(int argc, char*argv[]) {
  deque<int>items;
   set<int>contains;
 int pageSize=atoi(argv[1]);
     
    int count=pageSize; int pageFaults=0; int lines=0;
  while(count>0) {
       
     items.push_back(-1);//creates dummy
       --count;

         }

char read[10]; int Pagenum;

 while(fgets(read,sizeof(read),stdin)) {
           ++lines;
	if(!(isdigit((int)(read[0])))) {
               continue;

                }
    
	 sscanf(read,"%d",&Pagenum);
      
	set<int>::iterator it=contains.find(Pagenum);
           

	if(it==contains.end()) {
               ++pageFaults;
		 printf("Page number %d caused a page fault.\n",Pagenum);
             
	          int out=items.front(); //access first element
                 
                  contains.erase(out);
                    
                 items.pop_front();//remove first element
                
		 items.push_back(Pagenum); //insert new element
               
		 contains.insert(Pagenum); //insert in set
              
		 
             
                }
           else {

             continue;
                  }


  



    
  


}//while loop bracket

printf("The number of lines is %d and the number of page faults is %d\n",lines,pageFaults);

return 0;

}
