class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>> diffVsProfit;
        
        int n = difficulty.size();
        
        for(int i=0; i<n; i++){
            diffVsProfit.push_back({difficulty[i],profit[i]});
        }
        
        sort(diffVsProfit.begin(),diffVsProfit.end());
        
        for(int i=0; i<n-1; i++){
            diffVsProfit[i+1].second = max(diffVsProfit[i].second,diffVsProfit[i+1].second);
        }
        n = worker.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int l = 0,r = diffVsProfit.size()-1,mxProfit = 0;
            while(l<=r){
                int mid = (r+l)/2;
                if(diffVsProfit[mid].first > worker[i]){
                    r = mid - 1;
                }
                else{
                    mxProfit = max(mxProfit,diffVsProfit[mid].second);
                    l = mid + 1;
                }
            }
           
            ans += mxProfit;
            
        }
        return ans;
    }
};