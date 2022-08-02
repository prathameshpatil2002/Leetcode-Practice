class Solution {
public:
    int majorityElement(vector<int>& nums) {
      map<int,int> m;
      int is_major = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            m[nums[i]]++;
        }
        for(auto it : m){
            if(it.second > ceil(n/2)){
                is_major = it.first;
            }
        }
        return is_major;
    }
};