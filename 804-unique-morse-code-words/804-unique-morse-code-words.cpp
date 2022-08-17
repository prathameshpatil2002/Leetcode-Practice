class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string>m;
        m['a'] = ".-";
         m['b'] = "-...";
         m['c'] = "-.-.";
         m['d'] = "-..";
         m['e'] = "."; m['o'] = "---";
         m['f'] = "..-.";
         m['g'] = "--.";
         m['h'] = "...."; m['p'] = ".--.";
         m['i'] = "..";
         m['j'] = ".---";
         m['k'] = "-.-";
         m['l'] = ".-..";
         m['m'] = "--";
         m['n'] = "-.";
        m['q'] = "--.-";
        m['r'] = ".-.";
        m['s'] = "...";
        m['t'] = "-";
        m['u'] = "..-";
        m['v'] = "...-";
        m['w'] = ".--";
        m['x'] = "-..-";
        m['y'] = "-.--";
        m['z'] = "--..";
        
        set<string>s;
        
        for(auto it : words){
            string s1 = "";
            for(auto i : it){
                s1+=m[i];
            }
            s.insert(s1);
        }
         
        return s.size();
        
    }
};