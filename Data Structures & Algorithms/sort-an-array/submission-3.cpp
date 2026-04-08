class Solution {
public:

    int partition(vector<int>& nums, int left, int right) {

        int randIndex = (rand() % (right - left)) + left + 1;
        swap(nums[randIndex], nums[right]);

        int i = left - 1;
        for (int j = left ; j < right ; j++) {
            if (nums[j] < nums[right]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[right]);

        return (i + 1);

    }


    void quickSort(vector<int>& nums, int left, int right) {

        if (left >= right) return;

        int pivot = partition(nums, left, right);

        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};