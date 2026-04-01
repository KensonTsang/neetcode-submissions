class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> hash;

        for(int& num : nums) {
            if (hash.find(num) == hash.end()) {
                hash.insert(num);
            }
        }

        
        int length = 0;
        for(int num : nums) {            
            if (hash.find(num - 1) == hash.end()) {                
                int pushN = 0;
                while (hash.find(num + pushN) != hash.end()) {
                    pushN++;                
                }
                if (pushN > length) {
                    length = pushN;
                }
            }
        }

        return length;

    }
};
