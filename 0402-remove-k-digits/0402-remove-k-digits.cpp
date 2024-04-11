class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
        
        for(int i=0; i<num.size(); i++){
            int curr = num[i] - '0';
            while(!s.empty() && k > 0){
                int top = s.top();
                if(top > curr){
                    s.pop();
                    k-=1;
                }
                else{
                    break;
                }
            }
            s.push(curr);
        }
        
        while(k && !s.empty()){
            s.pop();
            k--;
        }
        string ret;
              
        while(!s.empty()){
            int top = s.top();
            ret.push_back(top + '0');
            s.pop();
        }
        while(ret.size()>0 && ret[ret.size()-1] == '0'){
            ret.pop_back();
        }
        reverse(ret.begin(),ret.end());
        if(ret == ""){
            ret += "0";
        }      
        return ret;
              
    }
};