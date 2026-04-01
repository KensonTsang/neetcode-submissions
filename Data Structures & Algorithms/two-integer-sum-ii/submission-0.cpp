class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        
        vector<int> result{};

        while(l < r){
            int find = target - numbers[l];
            if (numbers[r] > find) {
                r--;
                continue;
            }

            if (numbers[r] < find) {
                l++;
                continue;
            }

            if (numbers[r] == find) {
                result.push_back(l + 1);
                result.push_back(r + 1);
                return result;
            }

        }

        return result;

    }
};
