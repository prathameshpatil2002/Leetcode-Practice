class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        int ans = INT_MIN;
        
        for(int i=n-1; i>=2; i--){
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[i-2];
            long long a1 = 1LL*a*b;
            long long area = 1LL*a1*c;
            if((a+b > c)&&(a+c > b)&&(b+c > a)&&(area > 0)){
                ans = max(ans,(a+b+c));
            }
        }
        
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
        
    }
};