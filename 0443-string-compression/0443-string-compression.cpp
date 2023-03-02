class Solution {
public:
    int compress(vector<char>& s) {
        vector<char>ret;
        int n = s.size();
        
        
        if(n==1){
            ret.push_back(s[0]);
            s = ret;
            return 1;
        }
        int i = 0;
        while(i < n){
            int j = i;
            int cnt= 0;
            while(j<n){
                if(s[j]==s[i]){
                    cnt++;
                    j++;
                }
                else{
                    break;
                }
            }
            if(cnt==1){
                ret.push_back(s[i]);
            }
            else{
                ret.push_back(s[i]);
                stack<char>c;
                while(cnt > 0){
                    c.push(cnt%10+'0');
                    cnt/=10;
                }
                while(!c.empty()){
                    ret.push_back(c.top());
                    c.pop();
                }
            }
            i = j;
        }
        
        s = ret;
        return ret.size();
    }
};