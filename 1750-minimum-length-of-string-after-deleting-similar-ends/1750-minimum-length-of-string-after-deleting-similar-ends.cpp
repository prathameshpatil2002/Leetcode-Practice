class Solution {
public:
    int minimumLength(string s) {
        int i = 0 , j = s.size()-1;
        while(i<j){
            if(s[i] != s[j]){
                break;
            }
            else if(s[i] == s[j]){
                char c = s[i];
                while(i <= j){
                    if(s[i]==c){
                        i++;
                    }
                    else{
                        break;
                    }
                }
                while(j>i){
                    if(c==s[j]){
                        j--;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        return (j-i+1);
    }
};