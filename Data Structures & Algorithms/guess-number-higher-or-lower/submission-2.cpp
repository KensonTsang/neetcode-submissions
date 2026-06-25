/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        int l = 1;
        int r = n;
        
        while(l <= r) {
            int guessNum = (r - l) / 2 + l;
            int result = guess(guessNum);
            if (result == 0) {
                return guessNum;
            }
            else if (result > 0) {
                l = guessNum + 1;
            }
            else {
                r = guessNum - 1;
            }

        }

        return 0;

    }
};