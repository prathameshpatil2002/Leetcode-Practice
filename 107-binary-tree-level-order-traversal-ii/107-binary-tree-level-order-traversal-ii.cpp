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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            vector<vector<int>>ret({});
            return ret;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int>v;
            while(sz--){
                TreeNode* r = q.front();
                q.pop();
                
                v.push_back(r->val);
                if(r->left){
                    q.push(r->left);
                }
                if(r->right){
                    q.push(r->right);
                }
            }
            ret.push_back(v);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};