Solution 1. MLE
save every snap_id's array

Solution 2.
create a 2D array and initialize it like:
0:{0,0}     => pair {value, snap_id}
1:{0,0}
2:{0,0}
.
.
.
.
n:{0,0}

SET:
everytime we set a value, we first check if the index's last pair has the same number as current snap_id
=> if yes, means that we should overwirte it.
=> if not, means that we should push a new pair to it.

GET:
Use either linear search or binary search to find the first pair's snap_id that is smaller or equal to target snap_id

