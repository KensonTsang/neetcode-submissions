class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_arr[26] = {};
        int t_arr[26] = {};

        for (auto c : s) {
            int index = c - 'a';
            s_arr[index]++;
        }

        for (auto c : t) {
            int index = c - 'a';
            t_arr[index]++;
        }


        for (int i = 0 ; i < 26 ; i++) {
            if (s_arr[i] != t_arr[i]) {
                return false;
            }
        }


        return true;
    }
};
