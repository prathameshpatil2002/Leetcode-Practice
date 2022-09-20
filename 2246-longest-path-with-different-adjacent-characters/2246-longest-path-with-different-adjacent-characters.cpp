class Solution {
public:
    
    vector<vector<int>>graph;
    int ans = 1;
    int dfs(string& s, int i){
        int ret = 1;
        int ans1 = 0,ans2 = 0;
        
        for(auto it : graph[i]){
            int an = dfs(s,it);
            if(s[i]!=s[it]){
                if(an>=ans1){
                    ans2 = ans1;
                    ans1 = an;
                   
                }
                else if(an >= ans2){
                    ans2 = an;
                }
            }
        }
        ret = 1+ans1;
        
        ans = max(ans,ans1+ans2+1);
        
        return ret;
    }
    int longestPath(vector<int>& parent, string s) {
        graph.resize(parent.size());
        
        for(int i=1; i<parent.size(); i++){
            graph[parent[i]].push_back(i);
        }
        
        dfs(s,0);
        return ans;
    }
};