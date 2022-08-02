class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int  n= nums.size();
        queue<int> q;
        for(int i =0; i<n; i++){
            if(nums[i] != 0){
                q.push(nums[i]);
            }
        }
        for(int i =0; i<n; i++){
            if(nums[i] == 0){
                q.push(nums[i]);
            }
        }
        for(int i =0; i<n; i++){
           nums[i] = q.front();
            q.pop();
        }
        return;
        
    }
};