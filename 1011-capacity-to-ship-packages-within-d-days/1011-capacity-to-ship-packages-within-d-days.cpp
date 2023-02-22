class Solution {
public:
    bool checkAns(vector<int>& weights, int days, int mid) {
        int sum = 0;
        for(int w: weights) {
            if(w > mid) return false;
            sum += w;
            if(sum > mid) {
                days--;
                sum = w;
            }
        }
        return days > 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, h = 1e8;
        int ans = h;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(checkAns(weights, days, mid)) {
                ans = min(ans, mid);
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};