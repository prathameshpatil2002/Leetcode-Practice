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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*>q;
        int level = 0;
        q.push(root);
        
        while(!q.empty()){
            if(level%2){
                stack<TreeNode*>st;
                int sz = q.size();
                while(sz--){
                    TreeNode*node = q.front();
                    q.pop();
                    st.push(node);
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
                vector<int>v;
                while(!st.empty()){
                    v.push_back(st.top()->val);
                    st.pop();
                }
                 ans.push_back(v);
            }
            else{
                int sz = q.size();
                vector<int>v;
                while(sz--){
                    TreeNode*node = q.front();
                    q.pop();
                    v.push_back(node->val);
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
                
                ans.push_back(v);
            }
            level++;
        }
        return ans;
    }
};