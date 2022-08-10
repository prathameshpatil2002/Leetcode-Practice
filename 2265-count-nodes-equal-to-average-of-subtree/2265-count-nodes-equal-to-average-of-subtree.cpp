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
    int countNodes(TreeNode*root, map<TreeNode*,int>&m){
        if(root==NULL){
            return 0;
        }
        int l = countNodes(root->left,m);
        
        int r = countNodes(root->right,m);
        
        m[root] = l+r;
        
        if(root->left){
            m[root] += 1;
        }
        if(root->right){
            m[root] += 1;
        }
        
        return m[root];
    }
    
    void AsAvg(TreeNode*root,map<TreeNode*,int>&m){
        if(root==NULL){
            return;
        }
        
        AsAvg(root->left,m);
        
        AsAvg(root->right,m);
        
        int childs = m[root];
        
        int value = root->val;
        
        if(root->left){
            root->val += root->left->val;
        }
        
        if(root->right){
            root->val += root->right->val;
        }
        
        int avg = (root->val)/(childs+1);
        
        if(avg == value){
            count++;
        }
        
        
    }
    int averageOfSubtree(TreeNode* root) {
        map<TreeNode*,int>m;
        
        countNodes(root,m);
        
        AsAvg(root,m);
        
        return count;
    }
};