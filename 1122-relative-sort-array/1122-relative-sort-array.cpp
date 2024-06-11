class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto it : arr1){
            mp[it]++;
        }
        vector<int>ret;
        for(auto it: arr2){
            while(mp[it]){
                ret.push_back(it);
                mp[it]--;
            }
            mp.erase(it);
        }
        for(auto it : mp){
            while(it.second){
                ret.push_back(it.first);
                it.second--;
            }
            mp.erase(it.first);
        }
        return  ret;
    }
};