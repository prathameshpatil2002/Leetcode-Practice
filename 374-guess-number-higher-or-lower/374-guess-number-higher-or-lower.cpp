/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 1;
        int e = n;
        while(s<=e){
            int m = s + (e-s)/2;
            if(guess(m) == 0){
                return m;
            }
            else if(guess(m)==-1){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return e;
    }
};