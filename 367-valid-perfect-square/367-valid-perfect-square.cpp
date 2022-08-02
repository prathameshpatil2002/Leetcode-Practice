class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1;
        int e = num;
        while(s<=e){
            long long m = s+(e-s)/2;
            if(m*m == num){
                return true;
            }
            else if(m*m > num){
                e = m - 1;
                
            }
            else{
                s = m+1;
            }
        }
        return false;
    }
};