class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int left = INT_MAX,right = INT_MAX,up;
                
                if(j > 0){
                    left = dp[i+1][j-1];
                }
                if(j < n-1){
                    right = dp[i+1][j+1];
                }
                
                up = dp[i+1][j];
                
                dp[i][j] = min({left,right,up}) + matrix[i][j];
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            cout<<dp[0][i]<<" ";
            ans = min(ans,dp[0][i]);
        }
        
        return ans;
        
        
    }
};