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
    int sum;
    void dfs(TreeNode* root,int num){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            num *= 10;
            num += root->val;
            sum += num;
            return;
        }
        
        num *=10;
        num += root->val;
        dfs(root->left,num);
        dfs(root->right,num);
        
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root,0);
        
        return sum;
    }
};