//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       if(image[sr][sc] == newColor){
            return image;
        }
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        q.push({sr,sc});
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto curr = q.front();
                q.pop();
                
                int i = curr.first;
                int j = curr.second;
                int color = image[i][j];
                vis[i][j] = 1;
                
                if(i - 1 >= 0 && image[i-1][j] == color&& !vis[i-1][j]){
                    q.push({i-1,j});
                }
                if(i + 1 < n && image[i+1][j] == color&& !vis[i+1][j]){
                    q.push({i+1,j});
                }
                if(j - 1 >= 0 && image[i][j-1] == color&& !vis[i][j-1]){
                    q.push({i,j-1});
                }
                if(j+1<m && image[i][j+1] == color&& !vis[i][j+1]){
                    q.push({i,j+1});
                }
                image[i][j] = newColor; 
            }
        } 
        return image; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends