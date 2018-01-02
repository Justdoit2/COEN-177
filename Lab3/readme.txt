Alma Lucia Niu
COEN 177
11/9/17


		Number of Page Faults
Pages	 LRU     LFU 	FIFO	RANDOM
50		 4868	 4885	4865	4857
100		 4602	 4663	4591	4573
200		 4007	 4178	4000	4065
300		 3477	 3728	3496	3549
400	     3002	 3260	3026	3208
500	     2601	 2808	2616	2807

	Based on my chart, I can see that LRU is the best algorithm when we have larger page memory to prevent page faults. As the number of pages increase for LRU, the number of page faults decreases. In LFU, there is not much difference in terms of page faults compared with LRU in the beggining, with 50 pages. But as the memory becomes bigger, the number of page faults for LFU also decreases, but the gap difference between LRU and LFU starts to differ exponentially. 
When analyzing FIFO algorithm, I noticed how FIFO also had fewer page faults when dealing with bigger sized pages. In fact, FIFO worked slightly better or similar to LFU in terms of page fault ratio. In comparing the RANDOM algorithm, I noticed how was slightly better tha nLFU and FIFO at the beginning ,with fewer pages. But as more pages come into read, FIFO and LFU eventually start to catch up to RANDOM, and will eventually surpass RANDOM in terms of having less page faults.

	In LRU, the algorithm replaces page that is on the far left of the ccache, because it was least recently used. And the newest page is moved on the far right. If there is no page fault, the requested page is also bumped to the far right. LRU is the MOST EFFICIENT algorithm, based on my graph, because it takes into account that recently requested pages are more likely to be requested in the near future.  However, if page requests are requested with less pages, this algorithm is not as effective. 
	To improve my LRU  algorithm, I would improve LFU by adding a counter ot check how frequntly the page is being bumped back to the front. Therefore, I can tell that a certain page is always used and add them to another data structure such as a queue to prioritize that page.

	LFU is an algorithm where the new page will replace the page that has the fewest amount of request. If there is a tie in terms of frequency, then we depend on LRU to see which page has been in memory the longest to remove. I used a Page struct to keep track of the page number and frequency of uses for the pages. In terms of breaking frequency ties, I used a deque, pushing new items in the front. And as I move further along to the right of the deque, I can tell tell which page I should remove when breaking frequency ties, because the longest page will be the furthest right of the deque. 
	If I can improve my LFU, I will probably use a map, because it is a more efficient data structure that can keep track of the page number and frequency, as well as the ordering of the pages. And to break frequency ties, I know that a map add new elements to the back. So I just need to loop through the very front of the map to find the oldest page to remove (when breaking frequency ties).

	In FIFO, the algorithm replaces pages longest in memory  and add new elements at the back of a linked list or queue, only when the new pagenumber is not already in the queue. For this implementation, I used a queue and a set to keep track  of page numbers. Whenever a new pagenumber was not in the set, I push a page out of the front queue and add the new pagenumber to the back of the queue. I also removed the queue's front item from the original set, and add the new pagenumber to the new set. The set ensures that I have most up to date numbers in the queue.
	 To improve my implementation, I probably will try to use a linked list data structure instead, iterating the liked list to check if I find a page number. If I do, I continue. Else, I set the 2nd item in the linked list to head and add a new node at the tail with the new pagenumber.

	In RANDOM, the algorithm randomly removes an old page inside my array and replaces it with a new page. It is better than LFU, apparently in my graph.  Random is efficient because it is a fast algorithm that replaces the page in constant time. However, the downside of RANDOM is that it has no strategy in terms of predicting most frequent page requests. 
	If I can improve this algorithm, I would find ways to randomly jump through positions in my array that DOES NOT replace the most frequent page numbers, which will result in fewer page faults.
























	

