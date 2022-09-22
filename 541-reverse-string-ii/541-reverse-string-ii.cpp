class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i  = 0, j = 0;
        int ch = 0;
        while(j<n){
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1==k){
                if(!ch){
                    reverse(s.begin()+i,s.begin()+j+1);
                    ch = 1;
                }
                else{
                    ch = 0;
                }
                j++;
                i = j;
            }
        }
        if(j-i+1<=k){
                if(!ch){
                    reverse(s.begin()+i,s.end());
                    ch = 1;
                }
            }
        return s;
    }
};