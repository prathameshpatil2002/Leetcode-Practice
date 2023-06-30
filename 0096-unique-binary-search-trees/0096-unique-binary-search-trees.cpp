class Solution {
public:
    vector<int>dp;
    int func(int n) {
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += func(i-1)*func(n-i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp.resize(n+1,-1);
        return func(n);
    }
};