class Solution {
public:
    string countAndSay(int n) {
       if(n == 1){
           string ret = "1";
           return ret;
       }
        
        string s = countAndSay(n-1);
        string ret = "";
        int j = 0;
        while(j<s.length()){
            int cnt = 0;
            int k =j;
            while(s[j] ==s[k] && k < s.length()){
                k++;
                cnt++;
            }
            ret +=to_string(cnt);
            ret+= s[j];
            j = k;
           
        }
        return ret;
    }
};