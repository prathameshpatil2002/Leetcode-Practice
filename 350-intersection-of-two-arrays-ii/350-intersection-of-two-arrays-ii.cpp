class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ret;
        if(n > m){
            vector<int>idx(n,0);
            for(int i =0; i<m; i++){
                for(int j =0; j<n; j++){
                    if(nums2[i] == nums1[j] && !idx[j]){
                        ret.push_back(nums2[i]);
                        idx[j]=1;
                        break;
                    }
                }
            }
        }
        else{
            vector<int>idx(m,0);
            for(int i =0; i<n; i++){
                for(int j =0; j<m; j++){
                    if(nums1[i] == nums2[j] && !idx[j]){
                        ret.push_back(nums1[i]);
                        idx[j] = 1;
                        break;
                    }
                }
            }    
        }
        return ret;
    }
};