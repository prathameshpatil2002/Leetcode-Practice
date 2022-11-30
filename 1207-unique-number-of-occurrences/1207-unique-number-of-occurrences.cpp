class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        set<int>s;
        for(auto it : arr){
            m[it]++;
           
        }
        for(auto it : m){
            s.insert(it.second);
        }
        if(s.size()==m.size()){
            return true;
        }
        return false;
    }
};