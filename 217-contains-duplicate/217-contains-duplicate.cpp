class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto &it:nums){
            m[it]++;
        }
        
        for(auto it : m){
            if(it.second > 1){
                return true;
            }
            else{
                continue;
            }
        }
        return false;
    }
};