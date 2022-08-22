class Solution {
public:
    
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        
        float a = sqrt(n);
        
        if(!(n&(n-1))&&(a*a == n)){
            return true;
        }
        
        return false;
        
    }
};