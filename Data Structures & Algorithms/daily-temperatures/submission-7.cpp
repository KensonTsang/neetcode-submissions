class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> minSt{};
        vector<int> result (temperatures.size(), 0);

        for (auto i = 0 ; i < temperatures.size() ; i++) {
            
            while (minSt.size() > 0 && temperatures[i] > temperatures[minSt.top()]) {
                int index = minSt.top();
                minSt.pop();
                result[index] = i - index;
            }
            minSt.push(i);
        }

        return result;

    }
};
