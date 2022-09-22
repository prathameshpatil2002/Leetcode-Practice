class Solution {
public:
    string reverseWords(string s) {
        vector<string> w;
        string s2 = "" , ret= ""; s += " ";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                w.push_back(s2);
                s2 = ""; 
                continue;
            }
            else {
                s2 += s[i];
            }
        }
        for(int i = 0; i < w.size(); i++){
            for(int j = w[i].length() - 1; j >= 0; j--){
                ret += w[i][j];
            }
            if(i != w.size() - 1) ret += " ";
        }
        return ret;  
    }
};