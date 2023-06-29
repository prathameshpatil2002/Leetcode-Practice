class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0,o = 0,t=0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                z++;
            }
            else if(nums[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        int idx = 0;
        
        while(z--){
            nums[idx++] = 0;
        }
        
        while(o--){
            nums[idx++] = 1;
        }
        
        while(t--){
            nums[idx++] = 2;
        }
    }
};