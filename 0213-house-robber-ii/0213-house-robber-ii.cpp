class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0],nums[1]);}
        
        vector<int>dp(n),dp1(n+1);
        
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = max(dp[1],dp[0]+nums[1]);
        
        for(int i=3; i<n; i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        dp1[1] = 0;
        dp1[2] = nums[1];
        for(int i=3; i<=n; i++){
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i-1]);
        }
        return max(dp1[n],dp[n-1]);
    }
};