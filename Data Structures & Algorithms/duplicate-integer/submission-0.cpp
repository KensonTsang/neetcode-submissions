class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> appear{};

        for(auto& num : nums){
            if (appear.count(num)){
                return true;
            }

            appear.insert(num);
        }

        return false;

    }
};