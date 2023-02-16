class Solution {
public:
    int countOdds(int low, int high) {
        if(!low%2&&!high%2){
            int ans = (high-low)/2;
            return ans;
        }
        else if(low%2&&high%2){
            low--;
            high++;
            int ans = (high-low)/2;
            return ans;
        }
        else  if(low%2&high%2){
            low--;
            int ans = (high-low)/2;
            return ans;
        }
        
            high++;
            int ans = (high-low)/2;
            return ans;
        
    }
};