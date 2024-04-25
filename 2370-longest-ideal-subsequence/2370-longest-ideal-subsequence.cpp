class Solution {
public:
    int dfs(int i, int j,vector<vector<int>>&dp,string&s,int k){
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        dp[i][j] = 0;
        if(j == (s[i]-'a')){
            dp[i][j] = 1;
        }
        
        if(i > 0){
            dp[i][j] = dfs(i-1,j,dp,s,k);
            
            if(j == (s[i]-'a')){
                for(int c = 0; c<26; c++){
                    if (abs(j - c) <= k) 
                        dp[i][j] = max(dp[i][j],dfs(i-1,c,dp,s,k)+1);
                }
            }
        }
        return dp[i][j];
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(26,-1));
        
        int ret = INT_MIN;
        for(int i=0; i<26; i++){
            ret = max(ret,dfs(n-1,i,dp,s,k));
        }
        
        return ret;
    }
};