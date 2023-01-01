class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        
        for(auto it : s){
            if(st.empty() || st.top()!=it){
                st.push(it);
            }
            else{
                st.pop();
            }
        }
        
        string ret = "";
        
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(),ret.end());
        
        return ret;
    }
};