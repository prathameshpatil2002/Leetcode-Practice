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
    string ret ="";
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        ret += to_string(root->val);
        if(root->left && !root->right){
             ret += "(";
            solve(root->left);
            ret += ")";
        }
       else if(root->right && !root->left){
           ret += "()";
           ret += "(";
            solve(root->right);
            ret+=")";
       }
       else if(root->left && root->right){
            ret += "(";
            solve(root->left);
            ret += ")";
            ret += "(";
            solve(root->right);
            ret += ")";
       }
    }
    string tree2str(TreeNode* root) {
        solve(root);
        return ret;
    }
};