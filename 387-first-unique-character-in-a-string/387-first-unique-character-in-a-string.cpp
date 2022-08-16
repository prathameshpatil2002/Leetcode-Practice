class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> v;
        for(int i=0; i<s.length(); i++){
            v[s[i]]++;
        }
        int ans = -1;
        for(int i=0; i<s.length(); i++){
            if(v[s[i]] == 1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};