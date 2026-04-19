class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> map{};
        int l = 0;

        for (int r = 0 ; r < nums.size() ; r++) {

            if (r - l > k) {
                map.erase(nums[l]);    
                l++;
            }

            if (map.find(nums[r]) != map.end()) {
                return true;
            }

            map.insert(nums[r]);
        }

        return false;


    }
};