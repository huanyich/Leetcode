//
// IDEA FROM: 715. Range Module
// USE BINEARY SEARCH TO FIND THE PLACE TO DELETE AND THEN INSERT
class Solution {
public:
    map<int,int> Map; 
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> res;
        for(auto p:paint){
            int start = p[0];
            int end = p[1];

            int new_left = start;
            int new_right = end;

            //find the left part
            auto iter1 = Map.lower_bound(start);
            if(iter1!=Map.begin() && prev(iter1)->second >= start)
            {
                iter1 = prev(iter1);
                new_left = iter1->first;
            }

            //find the right prt
            auto iter2 = Map.upper_bound(end);
            if(iter2!=Map.begin() && prev(iter2)->second>= end)
            {
                new_right = prev(iter2)->second;
            }


            int prev_count = 0;
            for(auto it=iter1; it!=iter2; it++){
                prev_count+= (it->second-it->first);
            }

            Map.erase(iter1, iter2);
            Map[new_left] = new_right;

            res.push_back( new_right - new_left - prev_count);
            


        }
        return res;
    }
};


/*
      A       B         C
    [    ]  [  ]    [         ]
      [          ]
        new

    //find the left part
    auto iter1 = Map.lower_bound(start);
    if(iter1!=Map.begin() && prev(iter1)->second >= start)
    {
        iter1 = prev(iter1);
        new_left = iter1->left;
    }

    //find the right prt
    auto iter2 = Map.upperbound(end);
    if(iter2!=Map.begin() && prev(iter2)->second>= end)
    {
        new_right = prev(iter2)->second;
    }


    int prev_count = 0;
    for(auto it=iter1; it<iter2; it++){
        prev_count+= (it.second-it.first);
    }

    Map.erase(iter1, iter2);
    Map[new_left] = new_right;

    res.push_back( new_right - new_left - prev_count);



*/
