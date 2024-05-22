class Solution {
public:
    void generatePalindrome(int start, int end, string s, vector<vector<int>>& dp, vector<vector<string>>& palindromes, vector<string> subparts) {
        if (start >= end) {
            palindromes.push_back(subparts);
            return;
        }

        for (int i = start; i < end; i++) {
            bool palindrome = isPalindrome(start, i, s, dp);
            if (!palindrome)
                continue;

            subparts.push_back(s.substr(start, i - start + 1));
            generatePalindrome(i + 1, end, s, dp, palindromes, subparts);
            subparts.pop_back();
        }
    }

    bool isPalindrome(int left, int right, string s, vector<vector<int>>& dp) {
        if (dp[left][right] != -1)
            return dp[left][right] == 1;

        if (left >= right) {
            dp[left][right] = 1;
        } else if (s[left] == s[right]) {
            bool palindrome = isPalindrome(left + 1, right - 1, s, dp);
            dp[left][right] = palindrome ? 1 : 0;
        } else {
            dp[left][right] = 0;
        }

        return dp[left][right] == 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        generatePalindrome(0, s.size(), s, dp, palindromes, {});
        return palindromes;
    }
};