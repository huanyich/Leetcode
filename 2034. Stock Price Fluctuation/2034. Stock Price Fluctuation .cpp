class StockPrice {
public:
    unordered_map<int,int> mp;
    multiset<int> s;
    int curr=0;
    StockPrice() {   
    }
    
    void update(int timestamp, int price) {
        if(timestamp>curr) curr = timestamp;
        if(mp.count(timestamp)){
            int prev_price = mp[timestamp];
            s.erase(s.find(prev_price));
        }
        mp[timestamp] = price;
        s.insert(price);
        
    }
    
    int current() {
        return mp[curr];
    }
    
    int maximum() {
        return *s.rbegin();   
    }
    
    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
