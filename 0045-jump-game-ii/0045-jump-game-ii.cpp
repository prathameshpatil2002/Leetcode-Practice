class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 0;
    
        vector<int>dp(n,INT_MAX);
        
        dp[0] = 0;
        
        for(int i=0; i<n; i++){
            int curr = nums[i];
            for(int j=1; j<=curr; j++){
                if(i+j<n){
                    dp[i+j] = min(dp[i+j],dp[i]+1);
                }
            }
        }
        return dp[n-1];
    }
};