class MinStack {
public:

    stack<int> st;
    stack<int> minSt;

    MinStack() {
        st = {};
        minSt = {};
    }
    
    void push(int val) {
        
        st.push(val);

        if (minSt.size() > 0 && minSt.top() < val) {
            minSt.push(minSt.top());
        }
        else {
            minSt.push(val);
        }


    }
    
    void pop() {
        if (st.size() > 0) {
            st.pop();
        }

        if (minSt.size() > 0) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
