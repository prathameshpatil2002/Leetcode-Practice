class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int,int>mp;
        long long ans = 0;
        for(auto it : hours){
            int rem = it%24;

            if(rem == 0){
                ans+= mp[0];
            }
            else if(mp[24-rem] > 0)ans+=mp[24-rem];

            mp[rem]++;
        }
        return ans;
    }
};