class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result = {};

        for (int i = 0 ; i < nums.size() ; i++) {
            if ( i > 0 && nums[i - 1] == nums[i])
                continue;            

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0){
                    //..push to the result & l++ and r--;
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (sum < 0) {
                    // push the l pointer(l++)
                    l++;
                }
                else if (sum > 0) {
                    // push the r pointer(r--)
                    r--;
                }

            }


        }

        return result;

    }
};
