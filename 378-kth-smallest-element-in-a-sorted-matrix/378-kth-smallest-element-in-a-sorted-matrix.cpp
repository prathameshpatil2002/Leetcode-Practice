class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans = INT_MAX;
        vector<int>v;
       
        for(auto it : matrix){
            for(auto i : it){
                v.push_back(i);
            }
        }
        sort(v.begin(),v.end());
        return v[k-1];
    }
};