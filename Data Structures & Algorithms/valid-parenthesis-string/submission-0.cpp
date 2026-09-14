class Solution {
public:
    bool checkValidString(string s) {
        
        int lowUnmatchedLeft = 0;
        int highUnmatchedLeft = 0;

        for (char c : s) {
            if (c == '(') {
                lowUnmatchedLeft++;
                highUnmatchedLeft++;
            }
            else if (c == ')') {
                lowUnmatchedLeft--;
                highUnmatchedLeft--;
            }
            else {          // *
                lowUnmatchedLeft--;     // 第1個可能性是用作')', 所以low--
                highUnmatchedLeft++;    // 第2個可能性是用作'(', 所以high++
            }

            if (highUnmatchedLeft < 0) {    // ')('
                return false;
            }

            lowUnmatchedLeft = max(0, lowUnmatchedLeft);    // 第3個可能性是用作'string'
        }

        return lowUnmatchedLeft == 0;

    }
};
