class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        
        for(auto it : s){
            if(st.empty()||it!='*'){
                st.push(it);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
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