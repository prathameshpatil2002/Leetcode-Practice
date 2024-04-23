class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0){
            return {0};
        }
        vector<set<int>>g(n);
        vector<int>deg(n,0);
        for(auto it : edges){
            g[it[0]].insert(it[1]);
            g[it[1]].insert(it[0]);
            deg[it[0]]++;
            deg[it[1]]++;
        }
        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(deg[i] == 1){
                q.push(i);
            }
        }
        int nodes = n;
        while (nodes > 2) {
            int sz = q.size();
            nodes -= sz;
            while(sz--){
                int node = q.front();
                q.pop();
                for(auto it : g[node]){
                    deg[it]--;
                    if(deg[it] == 1){
                        q.push(it);
                    }
                }
            }
        }

        vector<int> mht;
        while (!q.empty()) {
            mht.push_back(q.front());
            q.pop();
        }
        return mht;
    }
};