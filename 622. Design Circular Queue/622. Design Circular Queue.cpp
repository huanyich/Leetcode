class MyCircularQueue {
public:
    vector<int> CQ;
    int K;
    MyCircularQueue(int k) {
        K = k;
    }
    
    bool enQueue(int value) {
        if(CQ.size()==K) return false;
        CQ.emplace(CQ.begin(), value);
        return true;
    }
    
    bool deQueue() {
        if(CQ.empty()) return false;
        CQ.pop_back();
        return true;
    }
    
    int Front() {
        if(CQ.empty()) return -1;
        return CQ[CQ.size()-1];
    }
    
    int Rear() {
        if(CQ.empty()) return -1;
        return CQ[0];
    }
    
    bool isEmpty() {
        return CQ.empty();
    }
    
    bool isFull() {
        return CQ.size()==K;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
