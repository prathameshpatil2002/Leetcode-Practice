class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>g;
        for(auto it : flights){
            g[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,int>>q;
        
        vector<int>dist(n,INT_MAX);
        
        q.push({src,0});
        
        int stops = 0;
        while(stops <= k && !q.empty()){
            int sz =  q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                
                for(auto it : g[p.first]){
                    if(dist[it.first] >= p.second+it.second){
                        dist[it.first] = p.second+it.second;
                        q.push({it.first,dist[it.first]});
                    }
                }
            }
            stops++;
        }
        if(dist[dst]==INT_MAX) return -1;
        
        return dist[dst];
    }
};