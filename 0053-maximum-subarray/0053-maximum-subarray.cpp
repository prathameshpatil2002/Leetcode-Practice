class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = INT_MIN;
        int till_sum = 0;
        int j = 0;
        while(j < nums.size()){
            till_sum += nums[j];
            
            if(till_sum >best_sum){
                best_sum = till_sum;
            }
            if(till_sum < 0){
                till_sum = 0;
            }
            j++;
        }
        return best_sum;
    }
};