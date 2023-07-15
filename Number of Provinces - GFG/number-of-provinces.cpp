//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&g, int node,vector<int>&vis){
        vis[node] = 1;
        
        for(auto it : g[node]){
            if(!vis[it]){
                dfs(g,it,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> g(V+1);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]&&i!=j){
                    g[i+1].push_back(j+1);
                }
            }
        }
        int ans = 0;
        vector<int>vis(V+1,0);
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                ans++;
                dfs(g,i,vis);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends