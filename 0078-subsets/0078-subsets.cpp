class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
         vector<vector<int>>ret;
        for(int i=0; i<pow(2,n); i++){
            vector<int>v;
            for(int j=0; j<n; j++){
                if(i&1<<j){
                    v.push_back(nums[j]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};