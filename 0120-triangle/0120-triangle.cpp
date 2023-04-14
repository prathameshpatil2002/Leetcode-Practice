class Solution {
public:

    int solve(int i, int curr, int n, vector<vector<int>>&triangle,vector<vector<int>>&dp) {
		if(i==n-1){
            return triangle[i][curr];
        }
        
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        
        int ith = solve(i+1,curr,n,triangle,dp);
        int i1th = solve(i+1,curr+1,n,triangle,dp);
        
        return dp[i][curr] = min(ith,i1th) + triangle[i][curr];
	}
	int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		int ans = solve(0,0,n,triangle,dp);
        return ans;
	}
};