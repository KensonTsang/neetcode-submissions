class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st{};    // minStack

        for (int i = 0 ; i < temperatures.size() ; i++) {
            while (st.size() > 0 && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                result[index] = i - index;
            }            
            st.push(i);
        }

        return result;

    }
};
