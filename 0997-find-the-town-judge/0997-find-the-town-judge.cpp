class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int tj = -1;
        
        vector<int>g[n+1];
        map<int,int>m;
        for(auto it : trust){
            g[it[1]].push_back(it[0]);
            m[it[0]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(g[i].size()==n-1&&m[i]==0){
                return i;
            }
        }
        return tj;
    }
};