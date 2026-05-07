class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        int r = 1;

        while (r < nums.size()) {            
            if (nums[r] == nums[r - 1]){
                r++;
                continue;
            }


            nums[l] = nums[r];
            l++;
            r++;     
        }

        return l;

    }
};