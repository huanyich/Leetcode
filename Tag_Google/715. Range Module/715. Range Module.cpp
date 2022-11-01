class RangeModule {
public:

    map<int,int> Map; // Map[start] = end
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto iter1 = Map.lower_bound(left);

        int new_left = left;
        int new_right = right;

        if(iter1!=Map.begin() && prev(iter1)->second >= left){
            iter1 = prev(iter1);
            new_left = iter1->first;
        }

        auto iter2 = Map.upper_bound(right);
        if(iter2!=Map.begin() && prev(iter2)->second>=right)
            new_right = prev(iter2)->second;

        
        Map.erase(iter1, iter2);

        Map[new_left] = new_right;

    }
    
    bool queryRange(int left, int right) {
        auto iter = Map.upper_bound(left);
        return iter!=Map.begin() && prev(iter)->second>=right;
    }
    
    void removeRange(int left, int right) {
        int start1=0,end1=0,start2=0,end2=0;
        auto iter1 = Map.lower_bound(left);
        if(iter1!=Map.begin() && prev(iter1)->second > left){
            iter1 = prev(iter1);
            start1 = iter1->first;
            end1 = left;
        }

        auto iter2 = Map.upper_bound(right);
        if(iter2!=Map.begin() && prev(iter2)->second >=right){
            start2 = right;
            end2 = prev(iter2)->second;
        }
        Map.erase(iter1, iter2);
        if(start1<end1) Map[start1] = end1;
        if(start2<end2) Map[start2] = end2;
    }
};

