addRange:
 we want to merge all the overlapped intervals, inorder to do so,
 find the [left...right] intervals that need to be deleted and add a new interval into it
 use binary search to do it.
 1. for the left most interval, we use lower_bound(left) to find the first interval's start that is bigger or equal to left.
 => if it is not the first and its previous one's ending is bigger than left, we need to start to delete from previous one;
 2. for the right most interval that need to be delete, use upper_bound(right) to find the first interval's start that is bigger than right,
 it's previous intervals will be overlapped if it existed


 queryRange:
 all the intervals are not overlapped,
 so we first search the first start point that is bigger than [left], it's previous' right must be bigger than right


 removeRange:
  Find out that no matter what it will need to insert 0~2 intervals
  the first interval is to find out the leftmost interval
    [ ][  ][  ][   ]
     [       ]
