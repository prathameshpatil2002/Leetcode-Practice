class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5+1,0));
        for(int i=1;i<=5;i++)dp[1][i]=i;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=5;j++){
                dp[i][j]= dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][5];
    }
};