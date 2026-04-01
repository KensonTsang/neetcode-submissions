class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // first is index, second is number of appear
        std::unordered_map<int, int> map;
        for(int num : nums) {
            map[num]++;
        }


        std::vector<std::vector<int>> bucket(nums.size() + 1);                
        for(auto pair : map) {
            bucket[pair.second].push_back(pair.first);
        }


        std::vector<int> result;        
        int bucket_index = bucket.size() - 1;
        while(k > 0 && bucket_index > 0) {
            if (!bucket[bucket_index].empty()) {
                result.push_back(bucket[bucket_index].back());
                bucket[bucket_index].pop_back();
                k--;
            }
            if(bucket[bucket_index].size() <= 0)
                bucket_index--;
        }

        
        return result;
        
    }
};
