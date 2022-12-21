class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>> &g, vector<int> &vis) {
        vis[node] = color;
        for(auto it : g[node]) {
            if(vis[it] == -1) {
                if(!dfs(it, 1 - color, g, vis)) return 0;
            }
            else if(vis[it] == color) return 0;
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>g(n+1);
        for(int i=0; i<dislikes.size();i++){
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>vis(n+1,-1);
        bool ret = 1;
        
        for(int i = 1; i <= n; ++i) {
            if(vis[i] == -1) {
                
                ret &= dfs(i, 0, g, vis); 
            }
        }
        return ret;
    }
};