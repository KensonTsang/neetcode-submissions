class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> result;

        int l = 0;
        for (int r = 0 ; r < nums.size() ; r++) {

           if (dq.size() > 0 && dq.front() < l) {
                dq.pop_front();
           }

            while (dq.size() > 0 && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(r);

            if (r - l + 1 == k) {
                result.push_back(nums[dq.front()]);
                l++;
            }

        }


        return result;

    }
};
