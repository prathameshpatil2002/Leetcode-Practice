class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
         int point = -1;
         for(int i=n-2;i>=0; i--){
             if(nums[i]<nums[i+1]){
                 point = i;
                 break;
             }
         }
        if(point == -1){
            sort(nums.begin(),nums.end());
            return;
        }
        
       for (int i = n - 1; i > point; i--) {
        if (nums[i] > nums[point]) {
            swap(nums[i], nums[point]);
            break;
        }
    }

    
    reverse(nums.begin() + point + 1, nums.end());

    }
};