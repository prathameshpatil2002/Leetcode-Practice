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
    void bfs(TreeNode*root,int val , int depth){
        queue<TreeNode*>q;
        int c = 0;        
        q.push(root);
        while(!q.empty()&&c < depth-2){
            int sz = q.size();
            while(sz--){
                TreeNode*node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                   
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
            c++;
        }
        while(!q.empty()){
            TreeNode* it = q.front();
            q.pop();
           
                TreeNode* n = new TreeNode(val);
                TreeNode* t = it->left;
                it->left = n;
                n->left = t;
                TreeNode* n1 = new TreeNode(val);
                TreeNode* t1 = it->right;
                it->right = n1;
                n1->right = t1;
            
        }
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        bfs(root,val,depth);
        
        return root;
    }
};