/*
for each interval there are 4 circumstances:
curr_left, curr_right
rleft, rright => to be removed
1.  devided into two.
    if( curr_left < rleft && rright < curr_right)
        first_part = {curr_left, rleft}; 
        second_part = {rright, curr_right};
        res.push_back(first_part);
        res.push_back(second_part)
2.current interval is all in toBeRemoved
    else if(rleft<=curr_left && curr_right<=rright)
        continue;
3.  not overlapped.
    else if(rrleft>curr_right || rright<curr_left){
        res.push_back({intervals[i]});
    }
4.  been cut a part.
    else{
                if(curr_left < rright && curr_right > rright) res.push_back({rright, curr_right});
                else res.push_back({curr_left,rleft});    
    }

*/
