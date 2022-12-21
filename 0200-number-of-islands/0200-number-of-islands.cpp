class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid , vector<vector<int>>& vis){
       
        
        if(j<n-1&&grid[i][j+1]=='1'&&!vis[i][j+1]){
            vis[i][j+1] = 1;
            dfs(i,j+1,m,n,grid,vis);
        }
        if(i<m-1&&grid[i+1][j]=='1'&&!vis[i+1][j]){
            vis[i+1][j] = 1;
            dfs(i+1,j,m,n,grid,vis);
        }
        if(j>0&&grid[i][j-1]=='1'&&!vis[i][j-1]){
            vis[i][j-1] = 1;
            dfs(i,j-1,m,n,grid,vis);
        }
        if(i>0&&grid[i-1][j]=='1'&&!vis[i-1][j]){
            vis[i-1][j] = 1;
            dfs(i-1,j,m,n,grid,vis);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int ans = 0;
        for(int  i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    vis[i][j] = 1;
                    dfs(i,j,m,n,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};