class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        if(nums.size()<=2){
            return -1;
        }
        sort(nums.begin(),nums.end());
        vector<long long>preSum(nums.size()+1);
        preSum[0]=0;
        for(int i=1; i<=nums.size();i++){
            preSum[i] = preSum[i-1] + nums[i-1]; 
        }
        int j = nums.size();
        while(j>=2){
            
            if(preSum[j-1] > nums[j-1]){
                return preSum[j];
            }
            j--;
        }
        return -1;
    }
};