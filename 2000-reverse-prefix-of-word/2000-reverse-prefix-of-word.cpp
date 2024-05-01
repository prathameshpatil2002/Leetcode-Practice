class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0,n = word.size();
        string rem = "",rev="";
        int f = 0;
        while(i < n){
            if(ch == word[i]){
                f = 1;
                break;
            }
            i++;
        }
        if(!f){
            return word;
        }
       
        int j = 0;
        while(j<=i){
            swap(word[i],word[j]);
            i--;
            j++;
        }
        return word;
    }
};