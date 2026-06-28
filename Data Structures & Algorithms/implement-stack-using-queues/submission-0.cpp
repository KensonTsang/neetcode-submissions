class MyStack {
public:

    queue<int> q;

    MyStack() {
        q = {};
    }
    
    void push(int x) {
        q.push(x);

        int swapSize = q.size() - 1;
        for (int i = 0 ; i < swapSize ; i++) {
            q.push(q.front());
            q.pop();
        }        
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
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