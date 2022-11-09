Solution: Monotonic Stack

Use a Stack a maintain it in a decreasing order, the stack saves a pair<int,int>.  
First is the price and Second is the number it is bigger than including itself.  
Every time we maintain the Stack we keep track of the numbers we popped out, it means that all of the numbers are smaller or equal than us.  
Return the count.  
