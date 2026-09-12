class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // push add the number to unordered_set 
        // loop N elements in unordered_set
        // if not contain N - 1, loop + 1 and max result, return result


        unordered_set<int> m{};
        for (int num : nums) {
            if (!m.count(num)) {
                m.insert(num);
            }
        }

        int result = 0;
        for (int entry : m) {            
            if (!m.count(entry - 1)) {  // this is head
                int plus = 0;
                while (m.count(entry + plus)) {                    
                    plus++;
                    result = max(result, plus);
                }
            }
        }

        return result;


    }
};
