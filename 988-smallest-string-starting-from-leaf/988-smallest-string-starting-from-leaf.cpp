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
    string ret;
    map<int,char> m;
    void dfs(string s, TreeNode* root){
        if(root==NULL){
            
            return;
        }
        if(!root->left&&!root->right){
            s.push_back(m[root->val]);    
            reverse(s.begin(),s.end());
            if(ret == ""){
                ret = s;
            }
            else if(ret > s){
                ret = s;
            }
            return;
        }
        
        s.push_back(m[root->val]);  
        dfs(s,root->left);
        dfs(s,root->right);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        char c = 'a';
        for(int i=0; i<=25; i++){
            m[i] = c;
            c++;
        }
        ret = "";
        dfs("",root);
        return ret;
    }
};