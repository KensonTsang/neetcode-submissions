class Solution {
public:

    void bracktrack(int openN, int closeN, int n, vector<string>& res, string& s) {
        if (openN == n && closeN == n) {
            res.push_back(s);
            return;
        }

        if (openN < n) {
            s.push_back('(');
            bracktrack(openN + 1, closeN, n, res, s);
            s.pop_back();
        }

        if (closeN < openN) {
            s.push_back(')');
            bracktrack(openN, closeN + 1, n, res, s);                        
            s.pop_back();
        }

    }


    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        string s = "";

        bracktrack(0, 0, n, res, s);
        return res;
    }
};
