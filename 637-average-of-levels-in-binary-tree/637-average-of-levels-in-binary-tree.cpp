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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ret;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int s1 = sz;
            long long sum = 0;
            while(sz--){
                TreeNode*node = q.front();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            double s = (1.00000*sum)/s1;
            ret.push_back(s);
        }
        return ret;
    }
};