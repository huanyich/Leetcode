class StockSpanner {
public:
    stack<pair<int,int>> Stack;
    // use a monotic staic in decreasing order
    StockSpanner() {        
    }
    int next(int price) {
        int count = 0;
        while(!Stack.empty() && Stack.top().first <= price){
            count+=Stack.top().second;
            Stack.pop();
        }
        count++; // itself
        Stack.push({price, count});
        return count;


    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 /*
[100,80,60,70,60,75,85]
[1,1,1,2,1,4,6]
<100,1><80,1><>

Map[value] = index


 */
