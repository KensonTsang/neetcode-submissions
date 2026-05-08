class MinStack {
public:

    stack<int> m_stack;
    stack<int> m_minStack;

    MinStack() {
        m_stack = {};
        m_minStack = {};
    }
    
    void push(int val) {
        m_stack.push(val);
        if (m_minStack.empty()) {
            m_minStack.push(val);
        }
        else{            
            m_minStack.push(min(m_minStack.top(), val));
        }
    }
    
    void pop() {
        m_stack.pop();
        m_minStack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_minStack.top();
    }
};
