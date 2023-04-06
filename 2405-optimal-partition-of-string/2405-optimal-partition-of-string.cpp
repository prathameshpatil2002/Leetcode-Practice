class Solution {
public:
    int partitionString(string s) {
        map<char,int>m;
        int count = 0;
        int i = 0;
        int n = s.size();
        int j = 0;
        while(j<n){
            if(m[s[j]]==0){
                m[s[j]]++;
                j++;
            }
            else if(m[s[j]] > 0){
                count++;
                int k = j-1;
                while(k >= i){
                    m[s[k]] = 0;
                    k--;
                }
                
                i = j;
                
            }
        }
        for(auto it : m){
            if(it.second > 0){
                count++;
                break;
            }
        }
        return count;
    }
};