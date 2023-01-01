class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k)return s;
        
        stack<pair<char,int>>st;
        
        for(auto it : s){
            if(st.empty() || st.top().first!=it){
                st.push({it,1});
            }
            else{
                auto p = st.top();
                st.pop();
                st.push({it,p.second+1});
                
                if(st.top().second == k){
                    st.pop();
                }
            }
        }
        
        string ret="";
        while(!st.empty()){
            auto p = st.top();
            while(p.second>0){
             ret.push_back(p.first);
             p.second--;
         }
            st.pop();
        }
        reverse(ret.begin(),ret.end());
        
        return ret;
    }
};