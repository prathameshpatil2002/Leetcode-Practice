class Solution {
public:
    bool possible(vector<int>bloomDay,int n,long long day, int m, int k){
        long long bloom = 0;
        long long nb = 0;
        for(int i=0; i<n; i++){
            if (bloomDay[i] <= day) {
                bloom++;
            } else {
                bloom = 0;
            }

            if (bloom == k) {
                nb++;
                bloom = 0;
            }
        }
        if(nb>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();  
        
        long long l = *min_element(bloomDay.begin(),bloomDay.end()),r = *max_element(bloomDay.begin(),bloomDay.end());
        long long ans = -1;
        while(l<=r){
            long long mid = (r+l)/2;
            
            if(possible(bloomDay,n,mid,m,k)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};