//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // map<int,set<string>>m;
        // map<string,set<int>>mp;
        // if(N==1){
        //     return arr[0];
        // }
        // int ans = INT_MIN;
        // for(int it = 0; it<N; it++){
        //     string s = "";
        //     for(int j=0; j<arr[it].size();j++){
        //         s.push_back(arr[it][j]);
        //         m[s.size()].insert(s);
        //         mp[s].insert(it);
        //         int a = s.size();
        //         ans = max(ans,a);
        //     }
        // }
        
        
        
        
        // for(int i=ans; i>=1; i--){
        //     for(auto it : m[i]){
        //         if(mp[it].size()==N){
        //             return it;
        //         }
        //     }
        // }
        
        // return "-1";
        
        string ans = "";
        
        int sz = INT_MAX;
        
        for(int i=0; i<N; i++){
            int a = arr[i].size();
            sz  = min(sz,a);
        }
        
        for(int i=0; i<sz; i++){
            set<char>s;
            for(int j=0; j<N; j++){
                s.insert(arr[j][i]);
            }
            if(s.size()==1){
                ans.push_back(arr[0][i]);
            }
        }
        
        if(ans==""){
            return "-1";
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends