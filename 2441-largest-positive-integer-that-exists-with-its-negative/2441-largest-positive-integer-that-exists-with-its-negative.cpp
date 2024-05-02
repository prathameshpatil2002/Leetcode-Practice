class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>m;
        for(auto it : nums){
            m[it]++;
        }
        int ans = INT_MIN;
        for(auto it  :  nums){
            if(it > 0){
                if(m[it*(-1)] > 0){
                    ans = max(ans,it);
                }
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};