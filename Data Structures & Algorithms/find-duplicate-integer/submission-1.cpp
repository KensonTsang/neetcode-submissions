class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slowIndex = nums[0];
        int fastIndex = nums[0];

        // Phase 1
        while (true) {
            slowIndex = nums[slowIndex];
            fastIndex = nums[nums[fastIndex]];

            if (slowIndex == fastIndex) {
                break;
            }
        }

        // Phase 2
        slowIndex = nums[0];

        while (slowIndex != fastIndex) {
            slowIndex = nums[slowIndex];
            fastIndex = nums[fastIndex];
        }

        return slowIndex;

    }
};
