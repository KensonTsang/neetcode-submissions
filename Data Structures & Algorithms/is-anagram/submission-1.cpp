class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_arr(26, 0);
        vector<int> t_arr(26, 0);

        for (auto c : s) {
            int index = c - 'a';
            s_arr[index]++;
        }

        for (auto c : t) {
            int index = c - 'a';
            t_arr[index]++;
        }

        return s_arr == t_arr;
    }
};
