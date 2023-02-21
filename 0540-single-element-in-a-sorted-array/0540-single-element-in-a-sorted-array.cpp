class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        //1 1 2
        while(i<n-1){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
            i+=2;
        }
        if(i==n){
            return nums[n-1];
        }
        return -1;
    }
};