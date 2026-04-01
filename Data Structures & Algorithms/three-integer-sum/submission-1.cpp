class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort (nums.begin(), nums.end());

       vector<vector<int>> result{};

        for (int i = 0 ; i < nums.size() ; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1; 

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left - 1] == nums[left]) left++;
                    while(left < right && nums[right + 1] == nums[right]) right--;
                }
                else if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
            }

        }

        return result;

    }
};
