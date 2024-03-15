class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        long lp = 1;
        int n = nums.size();
        vector<int> prod(n);
        for (int i = 0; i < n; i++)
        {
            prod[i] = lp;
            lp = lp * nums[i];
        }

        long rp = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            prod[i] = prod[i] * rp;
            rp = rp * nums[i];
        }
        
        return prod;
    }
};