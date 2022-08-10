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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1){
            return root2;
        }
        if(!root2){
            return root1;
        }
        
        TreeNode* l = mergeTrees(root1->left,root2->left);
        
        TreeNode* r = mergeTrees(root1->right,root2->right);
        
        TreeNode* root = new TreeNode(root1->val + root2->val);
        
        root->left = l;
        
        root->right = r;
        
        return root;
    }
};