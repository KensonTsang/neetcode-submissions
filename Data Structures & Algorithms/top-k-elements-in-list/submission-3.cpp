class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> mapping{};   // num as key, appear times as value

        for(const auto& num : nums) {
            mapping[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& entry : mapping) {
            buckets[entry.second].push_back(entry.first);
        }

        
        vector<int> result{};

        for (int i = buckets.size() - 1 ; i > 0 ; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
