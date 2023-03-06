class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int>m;
        for(int i=1; i<=1000; i++){
            m[i] = 0;
        }
        for(int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        int ans = 0;
        k--;
        for(auto it : m){
            if(it.second == 0){
                if(k == 0){
                    ans = it.first;
                    break;
                }
                else{
                    k--;
                }
            }
        }
        if(ans==0){
            ans = 1001;
            
            while(k > 0){
                k--;
                ans++;
            }
        }
        return ans;
    }
};