class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> minStack{};

        for (auto i = 0 ; i < temperatures.size() ; i++) {            
            while (minStack.size() > 0 && temperatures[i] > temperatures[minStack.top()]) {
                int topIndex = minStack.top();
                minStack.pop();
                result[topIndex] = i - topIndex;
            }
            minStack.push(i);
        }
        return result;
    }
};
