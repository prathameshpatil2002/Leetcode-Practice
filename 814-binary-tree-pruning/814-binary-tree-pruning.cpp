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
    pair<TreeNode*,int> solve(TreeNode* root){
        if(root == NULL){
            return {NULL,0};
        }
        
        pair<TreeNode*,int>l = solve(root->left);
        pair<TreeNode*,int> r = solve(root->right);
        
        if(l.second == 1 && r.second == 1){
            root->left = l.first;
            root->right = r.first;
            return {root,1};
        }
        
        else if(l.second){
            root->left = l.first;
            root->right = NULL;
            return {root,1};
        }
        else if(r.second){
            root->left = NULL;
            root->right = r.first;
            return {root,1};
        }
        
        if(root->val == 1){
            root->left = NULL;
            root->right = NULL;
            return {root,1};
        }
            
        return {NULL,0};
    }
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root).first;
    }
};