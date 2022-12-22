class Solution {
public:
    void dfs(vector<int>g[],int node ,int par,vector<int>&ans , vector<int>&dp, int depth){
        ans[0] += depth;
        dp[node] = 1;
        for(auto it : g[node]){
            if(par==it) continue;
            dfs(g,it,node,ans,dp,depth+1);
            dp[node] += dp[it];
        }
    }
    void dfs2(vector<int>g[],int n ,int node ,int par,vector<int>&ans , vector<int>&dp){
        for(auto it : g[node]){
            if(par==it) continue;
            ans[it] = ans[node] - dp[it] + (n-dp[it]);
            dfs2(g,n,it,node,ans,dp);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>g[n];
        for(auto it : edges){
            
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        int depth = 0;
        
        vector<int>dp(n,0);
        
        vector<int>ans(n,0);
        
        dfs(g,0,-1,ans,dp,depth);
        dfs2(g,n,0,-1,ans,dp);
        
        return ans;
        
    }
};