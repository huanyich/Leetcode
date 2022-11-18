We need two container to determine if the server is free or busy,  
for the free server, we use <strong>SET</strong> to store the numbers since we could apply bineary search in this container.  
For the busy container,we use a priority queue that stores pairs of variables <endTime, server>,   
the reason is every time we see if the startTime will be bigger than the endTime,  
if can, that means that the servers is free now, add them to the "free set".    

Time Complexity: every time we add in the pq takes O(nlogk) in total, so as the SET, k is the number of servers.
