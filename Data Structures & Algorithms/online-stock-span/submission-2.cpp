class StockSpanner {
public:

    stack<pair<int, int>> st; // 1st is price, 2nd is the number of contiune day

    StockSpanner() {
        st = {};
    }
    
    int next(int price) {
        
        int num = 0;
        while (st.size() > 0 && price >= st.top().first) {
            num += st.top().second;
            st.pop();
        }

        st.push({price, num + 1});
        
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */