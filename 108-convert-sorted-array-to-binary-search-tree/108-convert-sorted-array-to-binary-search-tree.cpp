/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convertToBST(int l,int r, vector<int>& nums){
        if(r<l){
            return NULL;
        }
        if(l==r){
            TreeNode*ret = new TreeNode(nums[l]);
            return ret;
        }
        
        int m = (l+r)/2;
        
        TreeNode* le = convertToBST(l,m-1,nums);
        
        TreeNode* ri = convertToBST(m+1,r,nums);
        
        TreeNode* root = new TreeNode(nums[m]);
        
        root->left = le;
        
        root->right = ri;
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0){
            return NULL;
        }
        return convertToBST(0,n-1,nums);
    }
};