class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        set<string>s;
        map<string,vector<string>>m;
        for(int i=0; i<n; i++){
            string s2= strs[i];
            sort(s2.begin(),s2.end());
            
            m[s2].push_back(strs[i]);
        }
        
        vector<vector<string>>ret;
        
        for(auto it : m){
            ret.push_back(it.second);
        }
        
        return ret;
    }
};