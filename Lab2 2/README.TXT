Task 1:
	In the first task, our goal is to find the source file, main.c, in the minix source code and edit the copyright message upon boot. I found the source file by going to the /usr/src/kernel directory in minix. As a result, I used ftp to transfer the main.c file to linux and edited this file by adding my name inside the copyright string. Then, I used ftp to transfer my edited file back to minix. Then, I did "make world" and rebooted the system, ensuring that the copyright message changed successfully.

Task 2:
	In the 2nd task, my goal is to modify the queue selection to add a slight possibility of choosing from a lower level or choose same level. My goal is to find and modify the proc.c file, as told by the instructor, in the usr/src/kernel directory. Initially, I did not find the proc.c, so my peer told me to type "make clean" to hopefully refresh and find the file. Fortunately,I found the file but it was empty after typing "make clean." As a result, I created a new minix environment and located the proc.c file with information inside it. The instructor told us to modify the pick_proc function and to type our code under the for-loop and above the if statement.
	  I know that there are 16 differently priority levels to choose from, and that it was recommended to not mess with priority 0-4, as this can crash the kernel. I know that if the highest priority queue is empty, it would check the queue with the next priority, until it finds a non-empty queue and select a process on that queue. 
	For my algorithm, I want to modify the scheduling if the priority is greater than 6. At first, I use the rand() function and mod it with the number of queues plus 7 to ensure lower priority. However, when I ran it in minix, my function crashed because I had an out of index for the number of queues. If my random number was 15 and I added an additional 7, then my level will be 22, which is greater than the number of available priority levels. After several trials, I decided to mod the random function with the number of scheduled queues minus 7, before adding 7, to ensure that I won't run into an out of level error. And this worked after running make world and rebooting the system. 
	

	 


