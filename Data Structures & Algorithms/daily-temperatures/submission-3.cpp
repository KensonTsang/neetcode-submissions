class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> minStack{};

        for (int i = 0 ; i < temperatures.size() ; i++) {

            while (minStack.size() > 0 && temperatures[i] > temperatures[minStack.top()]) {
                int top = minStack.top();
                int diff = i - top;
                minStack.pop();
                result[top] = diff;
            }
            minStack.push(i);
        }

        return result;

    }
};
