class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int curr = nums[n-1];
        int pre = nums[n-1];
        int max = nums[n-1];
        int tf = 1;
        int numDis = 1;
        int p = nums[0];
        int c = nums[0];
        for(int i=1; i<n; i++){
            c = nums[i];
            if(p==c){
                p = c;
                continue;
            }
            p=c;
            numDis++;
        }
        if(numDis<3){
            return nums[n-1];
        }
        for(int i=n-2;i>=0; i--){
            curr = nums[i];
            if(pre==curr){
                pre = curr;
                continue;
            }
            else{
                max = curr;
                tf++;
                pre = curr;
                if(tf==3){
                    break;
                }
            }
        }
        return max;
    }
};