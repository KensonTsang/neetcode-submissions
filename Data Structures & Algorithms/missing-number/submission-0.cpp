class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        // XOR 0 to n
        for (int i = 0 ;i <= n ; i++) {
            ans ^= i;
        }

        // XOR nums[i] element
        for (int i = 0 ; i < n ; i++) {
            ans ^= nums[i];
        }

        return ans;

    }
};
