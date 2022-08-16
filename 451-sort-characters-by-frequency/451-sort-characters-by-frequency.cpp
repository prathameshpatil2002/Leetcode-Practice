class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto it : s){
            m[it]++;
        }
        
        vector<pair<int,char>>p;
        for(auto it : m){
            p.push_back({it.second,it.first});
            
        }
        
        sort(p.begin(),p.end());
        
        reverse(p.begin(),p.end());
        
        string ret ="";
        
        int i = 0;
        int n = p.size();
        while(i<n){
            if(p[i].first > 0){
                ret.push_back(p[i].second);
                p[i].first--;
            }
            else{
                i++;
            }
        }
        
        return ret;
    }
};