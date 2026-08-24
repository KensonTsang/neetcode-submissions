class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2) {
            return n;
        }

        vector<int> result(n + 1, 0);
        result[1] = 1;
        result[2] = 2;

        for (int i = 3 ; i < result.size() ; i++) {
            result[i] = result[i - 1] + result[i - 2];
        }
        
        return result[n];
        

    }
};
