class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(!obstacleGrid[0][0]){
                dp[0][0] = 1;
            }
        else{
            dp[0][0] = 0;
        }
        for(int i=1; i<m; i++){
            if(!obstacleGrid[i][0]){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1; i<n; i++){
            if(!obstacleGrid[0][i]){
                dp[0][i] = dp[0][i-1];
            }
        }
        // if(dp[0][0] == 0){
        //     return 0;
        // }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(!obstacleGrid[i][j]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};