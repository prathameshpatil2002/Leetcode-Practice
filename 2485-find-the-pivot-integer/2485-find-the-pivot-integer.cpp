class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = (n*(n+1))/2;
        
        int rest_sum = 0;
       
        while(n>0){
             if(total_sum == (rest_sum+n)){
                 break;
             }
            total_sum -= n;
            rest_sum += n;
            n--;
        }
        if(n>0) return n;
        return -1;
    }
};