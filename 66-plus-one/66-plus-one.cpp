class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1] += 1;
        vector<int>v;
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i] >= 10){
                if(i == 0){
                    digits[i] = 0;
                    v.push_back(0);
                    v.push_back(1);
                }
                else{
                    int x = digits[i];
                    digits[i] %=10; 
                    digits[i-1] += x/10;
                    v.push_back(digits[i]);    
                }
                
            }
            else{
               v.push_back(digits[i]); 
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};