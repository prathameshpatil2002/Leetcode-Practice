class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto it : arr){
            m[it]++;
        }
        
        vector<pair<int,int>>v;
        for(auto it : m){
            v.push_back({it.second,it.first});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        set<int>s;
        int n = arr.size();
        int c = n/2;
        for(auto it : v){
            if(n<=c){
                break;
            }
            n -= it.first;
            s.insert(it.second);
        }
        
        return s.size();
    }
};