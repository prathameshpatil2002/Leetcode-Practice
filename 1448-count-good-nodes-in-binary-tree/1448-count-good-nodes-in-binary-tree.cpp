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
    int count = 0;
    void dfs(TreeNode* root,int prev,map<TreeNode*,int>&m){
        if(root==NULL){
            return;
        }
        if(prev==INT_MIN){
            m[root] = root->val;
            prev = root->val;
            
        }
        else{
            if(prev < root->val){
                m[root] = root->val;
                prev = root->val;
            }
            else{
                m[root] = max(prev,root->val); 
            }
            
            
        }
        
        dfs(root->left,prev,m);
        dfs(root->right,prev,m);
    }
    void dfs1(TreeNode*root,map<TreeNode*,int>&m){
        if(root==NULL){
            return;
        }
        if(m[root] <= root->val){
            count++;
        }
        
        dfs1(root->left,m);
        dfs1(root->right,m);
    }
    int goodNodes(TreeNode* root) {
        
        map<TreeNode*,int>m;
        
        
        
        dfs(root,INT_MIN,m);
        
        dfs1(root,m);
        return count;
        
    }
};