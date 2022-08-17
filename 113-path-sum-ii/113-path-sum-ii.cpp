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
    vector<vector<int>>ret;
    void dfs(TreeNode* root , int sum , int target , vector<int> v){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            sum += root->val;
            v.push_back(root->val);
            if(sum == target){
                ret.push_back(v);
                return;
            }
            return;
        }
        
        sum += root->val;
        v.push_back(root->val);
        dfs(root->left,sum,target,v);
        dfs(root->right,sum,target,v);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        dfs(root,0,targetSum,v);
        
        return ret;
    }
};