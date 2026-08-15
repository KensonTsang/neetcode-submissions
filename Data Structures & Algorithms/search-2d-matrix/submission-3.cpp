class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int top = 0;
        int bottom = row - 1;

        int targetRow = 0;
        bool isCorrect = false;
        while (top <= bottom) {

            int mRow = (top + bottom) / 2;

            if (target > matrix[mRow][col - 1]) {
                top = mRow + 1;
            }
            else if (target < matrix[mRow][0]) {
                bottom = mRow - 1;
            }
            else {
                targetRow = mRow;
                isCorrect = true;
            }
        }

        if (!isCorrect) {
            return false;
        }


        int l = 0;
        int r = col - 1;

        while (l <= r) {            
            
            int m = (l + r) / 2;

            if (target > matrix[targetRow][m]) {
                l = m + 1;
            }
            else if (target < matrix[targetRow][m]) {
                r = m - 1;
            }
            else {
                return true;
            }

        }


        return false;


    }
};
