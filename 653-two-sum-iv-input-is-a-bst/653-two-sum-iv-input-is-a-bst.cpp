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
    void inorder(vector<int>&ret,TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(ret,root->left);
        ret.push_back(root->val);
        inorder(ret,root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ret;
        inorder(ret,root);
        int i = 0;
        int j = ret.size()-1;
        while(i<j){
            int sum = ret[i]+ret[j];
            if(sum == k){
                return true;
            }
            else if(sum > k){j--;}
            else{
                i++;
            }
        }
        return false;
    }
};