class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char,int> m;
        int k = 1;
        for(char x = 'A'; x<='Z'; x++){
            m[x] = k;
            k++;
        }
        int c = 0;
        for(int i=0; i<columnTitle.size(); i++){
            c = c*26 + m[columnTitle[i]];
        }
        return c;
    }
};