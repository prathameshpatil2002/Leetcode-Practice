class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it :nums){
            sum+=it;
        }
        int real = (n*(n+1))/2;
        
        int ret = real - sum;
        return ret;
    }
};