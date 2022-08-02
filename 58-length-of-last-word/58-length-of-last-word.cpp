class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        while(s[s.length()-1]==' '){
            s.pop_back();
        }
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==' ' ){
                break;
            }
            else{
                c++;
            }
        }
        return c;
    }
};