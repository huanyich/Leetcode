Solution 1:
simulate every level, use queue

Solution 2:
traverse from left to right
use a variable "right" to track the the nearest element R
When meet a 'L'
=> if right is != -1, means there are a R havent handle yet
=> if right == 1, means all the '.' is left side need to be 'L'

When meet a 'R'
=> if right !=-1, means elements in right to i must all be 'R'
=> if right == -1, right to i should all be 'R'
