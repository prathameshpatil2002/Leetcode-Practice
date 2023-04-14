class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m)));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(i==j){
                    dp[n-1][i][j] = grid[n-1][i];
                }
                else{
                    dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
                }
            }
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-1;j>=0;j--){
                for(int k=m-1;k>=0; k--){
                    int a1 = INT_MIN,a2 = INT_MIN,a3 = INT_MIN,a4 = INT_MIN,a5 = INT_MIN,a6 = INT_MIN,a7 = INT_MIN,a8 =  INT_MIN,a9 = INT_MIN;
                    a1 = dp[i+1][j][k];
                    if(k < m-1){
                        a2 = dp[i+1][j][k+1];
                    }
                    if(k > 0){
                        a3 = dp[i+1][j][k-1];
                    }
                    if(j<m-1){
                        a4 = dp[i+1][j+1][k];
                    }
                    if(k < m-1&&j<m-1){
                        a5 = dp[i+1][j+1][k+1];
                    }
                    if(k > 0&&j<m-1){
                        a6 = dp[i+1][j+1][k-1];
                    }
                    
                    if(j>0){
                        a7 = dp[i+1][j-1][k];
                    }
                    if(k < m-1&&j>0){
                        a8 = dp[i+1][j-1][k+1];
                    }
                    if(k > 0&&j>0){
                        a9 = dp[i+1][j-1][k-1];
                    }
                    
                    dp[i][j][k] = max({a1,a2,a3,a4,a5,a6,a7,a8,a9});
                    
                    if(j==k){
                        dp[i][j][k] += grid[i][j];
                    }
                    else{
                         dp[i][j][k] += (grid[i][j] + grid[i][k]);
                    }
                }
            }
        }
        
        
        
        return dp[0][0][m-1];
        
    }
};