class Solution {
public:

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;

        for (size_t j = left ; j < right ; j++) {
            if(nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[right]);

        return (i + 1);
    }


    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pi = partition (nums, left, right);
            quickSort(nums, left, pi - 1);
            quickSort(nums, pi + 1, right);
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }


};