class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it : words){
            int i = 0, j = it.size()-1;
            int pal = 1;
            while(i<j){
                if(it[i] == it[j]){
                    i++;
                    j--;
                }
                else{
                    pal = 0;
                    break;
                }
            }
            if(pal){
                return it;
            }
        }
        return "";
    }
};