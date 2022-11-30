Solution: Sort + BinearySearch + DP

We don't need to consider every point, we just need to consider the points that is valid.  
To do so, we first gather all the three arrays into a single array, then sort it.  
The reason to sort the array is that we want to make sure the startTime is in order so we could apply bineary search later when we are trying to find the next possible points.  
