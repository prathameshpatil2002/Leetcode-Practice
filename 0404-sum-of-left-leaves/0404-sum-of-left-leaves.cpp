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
    void sumOfLeftLeavesHelp(TreeNode*root,int &sum){
        if(!root){
           
            return;
        }
        sumOfLeftLeavesHelp(root->left,sum);
        sumOfLeftLeavesHelp(root->right,sum);
        if(root->left&&!root->left->left&&!root->left->right){
            sum += root->left->val;
            return;
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum = 0;
        sumOfLeftLeavesHelp(root,sum);
       
        return sum;
    }
};