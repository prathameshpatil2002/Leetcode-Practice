class Solution {
public:
   
    bool isWordInDict(const string& word, const vector<string>& wordDict) {
        for (const auto& dictWord : wordDict) {
            if (dictWord == word) {
                return true;
            }
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       
        unordered_map<int, vector<string>> dp;

       
        for (int startIdx = s.size(); startIdx >= 0; startIdx--) {
            
            vector<string> validSentences;

            
            for (int endIdx = startIdx; endIdx < s.size(); endIdx++) {
               
                string currentWord = s.substr(startIdx, endIdx - startIdx + 1);

               
                if (isWordInDict(currentWord, wordDict)) {
                   
                    if (endIdx == s.size() - 1) {
                        validSentences.push_back(currentWord);
                    } else {
                        
                        vector<string> sentencesFromNextIndex = dp[endIdx + 1];
                        for (const auto& sentence : sentencesFromNextIndex) {
                            validSentences.push_back(currentWord + " " +
                                                     sentence);
                        }
                    }
                }
            }
           
            dp[startIdx] = validSentences;
        }
        
        return dp[0];
    }
    
};