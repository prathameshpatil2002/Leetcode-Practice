class Solution {
public:
    void dfs(int source,int des,vector<vector<int>>&g,vector<int>&vis){
        vis[source] = 1;
        if(source == des){
            return;
        }
        vis[source] = 1;
        for(auto it : g[source]){
            if(!vis[it]){
                dfs(it,des,g,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>g(n);
        vector<int>vis(n,0);
        for(auto it : edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
         dfs(source,destination,g,vis);
         if(!vis[destination]){
             return false;
         }
        return true;
    }
};