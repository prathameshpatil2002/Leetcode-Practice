class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        int i;
        int n = nums.size();
        for(i =0; i<n; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        i = 0;
        int j = v.size()-1;
        vector<int>ret;
        while(i < j){
            int sum = v[i].first + v[j].first;
            if(sum == target){
                ret.push_back(v[i].second);
                ret.push_back(v[j].second);
                i++;
                j--;
                break;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ret;
    }
};