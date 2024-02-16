class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
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
        
        while(k--){
            if(v[v.size()-1].first == 1){
                v.pop_back();
            }
            else{
                v[v.size()-1].first -= 1;
            }
        }
        return v.size();
    }
};