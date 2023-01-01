class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>m;
        if(s.size()!=t.size()){
            return false;
        }
        map<char,int>m1;
        for(int i=0; i<s.size(); i++){
            if(m.find(t[i])==m.end()){
                if(m1[s[i]]!=0) return false;
                m[t[i]]=s[i];
                m1[s[i]]++;
            }
            else{
                if(m[t[i]]!=s[i]) return false;
                continue;
            }
        }
        string ts;
        for(int i=0; i<s.size(); i++){
           ts.push_back(m[t[i]]);
        }
        return ts==s;
    }
};