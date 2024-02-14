class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        stack<int>positive,negative;
        int size = nums.size();
        for(auto it : nums){
            if(it<0){
                negative.push(it);
            }
            else{
                positive.push(it);
            }
        }
        int i = 0;
        while(size>0){
            nums[i] = positive.top();
            nums[i+1] = negative.top();
            positive.pop();
            negative.pop();
            size-=2;
            i+=2;
        }
        reverse(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i+=2){
            swap(nums[i],nums[i+1]);
        }
        return nums;
    }
};