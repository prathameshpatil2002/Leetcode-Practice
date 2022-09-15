class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>m1;
        int n = changed.size();
        for(auto it : changed){
            m1[it]++;
        }
        vector<int>ret;
        
        sort(changed.begin(),changed.end());
        
        for(int i=0; i<n; i++){
            if(m1[changed[i]] > 0 && changed[i]!=0){
                if(m1[changed[i]*2] > 0){
                    ret.push_back(changed[i]);
                    m1[changed[i]*2]--;
                }
                m1[changed[i]]--;
            }
            else if(changed[i]==0&&m1[changed[i]] > 1){
                     if(m1[changed[i]*2] > 0){
                    ret.push_back(changed[i]);
                    m1[changed[i]*2]--;
                }
                m1[changed[i]]--;
            }
        }
        if(ret.size()*2 == changed.size()){
            return ret;
        }
        ret.clear();
        return ret;
    }
};