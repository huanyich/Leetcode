Solution: Sliding Window  
  
string s and t each has one map,  
t's map is for what the needed elements, called 'need'.  
s's map is for knowing the elements in the window, called 'window'.  
  

First traverse string t to construct the need map.  
Second,   
initialize, 'start', 'ans', 'left' and a for loop(right);  

if we find that the curr index's value could be found in 'need',  
we check if window[curr] < need[curr], if true means that we still need more 'curr',  
therefore count++,  
then we check if count==t.size() => means we have everything we need in this window  
=> Then we start to move left pointer to maintain the window and the answer until count is smaller than needed.  

At last, check if ans have been changed or not, if so, return the correct answer, otherwise means that there are no answer founeded, return "".
