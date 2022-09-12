class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int  n =  tokens.size();
        int score = 0;
        int ans = 0;
        int i = 0, j = n-1;
        sort(tokens.begin(),tokens.end());
        while(j>=i){
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
                ans = max(ans,score);
            }
            else if(score>=1){
                power += tokens[j];
                score--;
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};