class Solution {
public:

    int helper (int n) {
        int res = 0;

        while (n > 0) {
            res += n % 2;
            n = n >> 1;
        }

        return res;
    }

    vector<int> countBits(int n) {

        if (n == 0) {
            return {0};
        }

        vector<int> res(n + 1, 0);

        for (int i = 1; i < res.size() ; i++) {
            res[i] = helper(i);
        }

        return res;

    }


};
