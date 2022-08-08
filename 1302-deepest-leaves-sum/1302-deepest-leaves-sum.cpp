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
    int sum = 0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int l = height(root->left);
        
        int r = height(root->right);
        
        return 1+ max(l,r);
    }
    
    void solve(TreeNode* root , int h){
        if(h==0){
            if(root!=NULL){
                sum += root->val;
            }
            return;
        }
        
        if(root->left){
            solve(root->left,h-1);
        }
        
        if(root->right){
             solve(root->right,h-1);
        }
       
    }
    int deepestLeavesSum(TreeNode* root) {
        
        int h = height(root);
        
        solve(root,h-1);
        
        return sum;
    }
};