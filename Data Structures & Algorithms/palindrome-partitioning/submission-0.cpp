class Solution {
public:

    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void backtrack(int i, const string& s, vector<string>& part, vector<vector<string>>& result) {
        if ( i >= s.size()) {
            result.push_back(part);
            return;
        }

        for (int j = i; j < s.size() ; j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j-i+1));
                backtrack(j + 1, s, part, result);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        backtrack(0, s, part, result);
        return result;
    }
};
