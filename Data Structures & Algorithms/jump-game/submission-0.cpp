class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int target = n - 1;

        for (int i = n - 1; i >= 0 ; --i) {

            int maxJump = nums[i];

            if ( i + maxJump >= target) {
                target = i;
            }
        }

        return target == 0;
    }
};
