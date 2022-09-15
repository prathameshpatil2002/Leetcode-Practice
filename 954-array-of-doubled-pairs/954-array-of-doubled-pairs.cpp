class Solution {
public:
    static bool cmp(int &a1,int &a2){
        return abs(a1)<abs(a2);
    }
    bool canReorderDoubled(vector<int>& arr) {
        map<long long,long long>m;
        int n = arr.size();
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        
        sort(arr.begin(),arr.end(),cmp);
        int pairs = 0;
        for(int  i=0; i<n; i++){
           if(m[arr[i]] == 0){
               continue;
           }
            if(m[arr[i]*2]==0){
                return false;
            }
            m[arr[i]]--;
            m[arr[i]*2]--;
        }
        
        return true;
        
    }
};