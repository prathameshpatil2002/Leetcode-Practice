//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        int no_count = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 0){
                    no_count++;
                }
            }
        }
        if((n*m) == no_count){
            return 0;
        }
        int time = -1; 
        int count = 0;
        
        while(!q.empty()){
            int sz = q.size();
            count += sz;
            time++;
            while(sz--){
                auto curr = q.front();
                q.pop();
                
                int i = curr.first;
                int j = curr.second;
                vis[i][j] = 1;
                
                if(i-1>=0&&!vis[i-1][j]&&grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                }
                if(j-1>=0&&!vis[i][j-1]&&grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                }
                if(i+1<n&&!vis[i+1][j]&&grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                }
                if(j+1<m&&!vis[i][j+1]&&grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                }
            }
        }
        
        if(count == (n*m - no_count)){
            return time;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends