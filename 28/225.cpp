class MyStack {
public:
    priority_queue<pair<int, int>> pq;
    int counter;
    MyStack() {
        counter = 0;
    }
    
    void push(int x) {
        counter++;
        pq.push({counter, x});
    }
    
    int pop() {
        int temp = pq.top().second;
        counter--;
        pq.pop();
        return temp;
    }
    
    int top() {
       return pq.top().second;
    }
    
    bool empty() {
        return counter == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */