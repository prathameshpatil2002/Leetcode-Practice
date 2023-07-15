class Solution {
public:
    void dfs(vector<vector<int>>&g , int node, vector<int>&vis){
        vis[node] = 1;
        
        for(int i=0; i<g.size(); i++){
            if(i==node){
                continue;
            }
            if(g[node][i]&&!vis[i]){
                dfs(g,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected, i, vis);
            }
        }
        return ans;
    }
};