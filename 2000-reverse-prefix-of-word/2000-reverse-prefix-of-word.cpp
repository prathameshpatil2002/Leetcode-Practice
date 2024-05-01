class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0,n = word.size();
        string rem = "",rev="";
        int f = 0;
        while(i < n){
            if(ch == word[i]){
                f = 1;
                rev = word.substr(0,i+1);
                rem = word.substr(i+1,n-(i+1));
                break;
            }
            i++;
        }
        if(!f){
            return word;
        }
       
        reverse(rev.begin(),rev.end());
        rev += rem;
        return rev;
    }
};