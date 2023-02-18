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
    
    void dfs(TreeNode*l,TreeNode*r,int level){
        if(!l&&!r){
            return;
        }
        if(level%2){
            int l1 = l->val;
            int r1 = r->val;
            
            l->val = r1;
            r->val = l1;
        }
        
        dfs(l->left,r->right,level+1);
        dfs(l->right,r->left,level+1);
        
    }
    
    void bfs(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>ret;
            stack<TreeNode*> s;
            level++;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                    
                if(node->left&&node->right){
                    q.push(node->left);
                    q.push(node->right);
                            
                    ret.push_back(node->left->val);
                    ret.push_back(node->right->val);
                            
                    s.push(node->left);
                    s.push(node->right);
                }
            } 
            if(level%2){
                    int i = 0;
                    int t = s.size();
                    while(t--){
                        TreeNode* x = s.top();
                        s.pop();
                        x->val = ret[i];
                        i++;
                }
            }
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }
};