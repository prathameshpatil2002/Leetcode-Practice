class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return e;
    }
};