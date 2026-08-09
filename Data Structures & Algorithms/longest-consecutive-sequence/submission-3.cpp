class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> mapping{};

        for (const int& num : nums) {
            mapping.insert(num);            
        }


        int result = 0;

        for (const int& num : mapping) {

            if (mapping.count(num - 1)) {
                continue;
            }

            int pushed = 0;
            while (mapping.count(num + pushed)) {
                pushed++;
                result = max(pushed, result);
            }
        }

        return result;
        
    }
};
