class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++)
            m[arr[i]].push_back(i);
        
        vector<int> vis(n,0);
        queue<int> q;

        q.push(0);
        vis[0] = 1;
        int ans = -1;

        while(!q.empty()) {
            int sz = q.size();
            ans++;

            while(sz--) {
                int i = q.front();
                q.pop();

                if(i == n-1)
                    return ans;

                vector<int>& v = m[arr[i]];

                if(i-1 >= 0)
                    v.push_back(i-1);
                
                if(i+1 < n)
                    v.push_back(i+1);
                
                for(int j : v) {
                    if(!vis[j]){
                        vis[j] = 1;
                        q.push(j);
                    }
                }
                v.clear();
            }
        }
        
        return 0;
    }
};