class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
       stack<int> t{};
       vector<int> result(temperatures.size(), 0);

        for(auto i = 0; i < temperatures.size() ; i++) {

            while (!t.empty() && temperatures[i] > temperatures[t.top()]) {
                int top = t.top();
                t.pop();
                result[top] = i - top;
            }

            t.push(i);
        }

        return result;

    }
};
