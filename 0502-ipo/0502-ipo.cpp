class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n = profits.size();
        for(int i=0; i<n; i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        
        for(int i=0; i<n; i++){
            if(w >= v[i].first) {
                pq.push(v[i].second);
            } else if(k > 0 && pq.size() > 0) {
                k--;
                i--;
                w += pq.top();
                pq.pop();
            }
        }
        while(pq.size() > 0 && k > 0) {
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};