class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length(); 

       
        int ones_cnt = 0;
        for (auto c: s) {
            ones_cnt += c - '0';
        }

        string result = "";
        for (int i = 0; i < ones_cnt - 1; i++) {
            result += "1";
        }
        for (int i = 0; i < n - ones_cnt; i++) {
            result += "0";
        }
        result += "1";
        return result;
    }
};