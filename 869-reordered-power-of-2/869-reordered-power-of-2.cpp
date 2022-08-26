class Solution {
public:
    string digitCount(int n){
        string ret = "";
        while(n){
            ret += to_string(n%10);
            n/=10;
        }
        sort(ret.begin(),ret.end());
        return ret;
        
    }
    bool reorderedPowerOf2(int n) {
        string nCount = digitCount(n);
        for(int i=0;i<32; i++){
            string ret = digitCount(1<<i);  // compute digit count of every power of two and compare;
                
            if(ret==nCount){
                return true;
            }
        }
        return false;
    }
};