class MedianFinder {
public:
    priority_queue<int> left; // maxHeap
    priority_queue<int, vector<int>, greater<int>> right; //minHeap 
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //first put in left
        left.push(num);
        right.push(left.top());
        left.pop();
        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }    
    }
    
    double findMedian() {
        return (right.size()+left.size())%2==0?(double)(left.top()+right.top())/2:(double)left.top();
    }
};
