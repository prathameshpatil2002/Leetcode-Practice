class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i=1; i<n; i++){
            min_so_far = min(prices[i],min_so_far);
            maxProfit = max(prices[i]-min_so_far,maxProfit);
        }
        return maxProfit;
    }
};