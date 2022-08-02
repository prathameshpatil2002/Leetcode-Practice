class Solution {
public:
    int solve(int n , int i, vector<int>&dp){
        if(i>n){
            return 0;
        }
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int r1 = solve(n,i+1,dp);
        int r2 = solve(n,i+2,dp);
        dp[i] = r1+r2;
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int i = 0;
        return solve(n,i,dp);
    }
};