class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>>v;
        int n = nums.size();
        int ans = -1;
        for(int i =0; i<n; i++){
            int x = nums[i];
            int s  = 0;
            while(x > 0){
                s+=x%10;
                x/=10;
            }
            v[s].push(nums[i]);
            
            if(v[s].size()>=2){
                int one = v[s].top();
                v[s].pop();
                int two = v[s].top();
                v[s].pop();
                
                ans = max(ans,one+two);
                 v[s].push(one);
                 v[s].push(two);
            }
            
        }
        
       return ans;
    }
};