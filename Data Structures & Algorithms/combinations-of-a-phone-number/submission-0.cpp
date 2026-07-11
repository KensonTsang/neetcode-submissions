class Solution {
public:

    vector<string> result{};
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    

    void backtrack(int i, string& curStr, string& digits) {
        if (curStr.size() == digits.size()) {
            result.push_back(curStr);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for (char c: chars) {
            curStr.push_back(c);
            backtrack(i+1, curStr, digits);
            curStr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.size() <= 0) {
            return result;
        }

        string combs = "";

        backtrack(0, combs, digits);
        return result;



    }
};
