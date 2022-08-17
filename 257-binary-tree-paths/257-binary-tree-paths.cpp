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
    vector<string>ret;
    void dfs(string s, TreeNode* root){
        if(root==NULL){
            //ret.push_back(s);
            return;
        }
        if(!root->left&&!root->right){
            s+= to_string(root->val);
            ret.push_back(s);
            return;
        }
        
        s+= to_string(root->val);  
        s+="->";
        dfs(s,root->left);
        dfs(s,root->right);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs("",root);
        
        return ret;
    }
};