class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            string k = "";
            for(auto it : strs){
                k.push_back(it[i]);
            }
            string s = k;
            sort(s.begin(),s.end());
            if(s!=k){
                ans++;
            }
        }
        return ans;
    }
};