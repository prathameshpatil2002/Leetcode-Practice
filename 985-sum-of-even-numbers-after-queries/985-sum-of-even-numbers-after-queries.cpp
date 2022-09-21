class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        map<int,int>m;
        int sum = 0;
        int n = nums.size();
        vector<int>ret;
        for(int i=0; i<n; i++){
            m[i] = nums[i];
            if(nums[i]%2==0){
                sum += nums[i];
            }
        }
        
        for(auto it : queries){
            int val = it[0];
            int idx = it[1];
            
            int value = m[idx];
            
            int tmp = value + val;
            
            if(value%2==0){
                if(tmp%2==0){
                    sum -= value;
                    sum += tmp;
                    m[idx] = tmp;
                }
                else{
                    sum -= value;
                    m[idx] = tmp;
                }
            }
            else{
                if(tmp%2==0){
                    sum += tmp;
                    m[idx] = tmp;
                }
                else{
                    m[idx] = tmp;
                }
            }
            
            ret.push_back(sum);
        }
        return ret;
    }
};