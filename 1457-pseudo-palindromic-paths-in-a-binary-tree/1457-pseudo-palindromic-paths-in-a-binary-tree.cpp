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
    map<int,int>m;
    int ans = 0;
    int till = 0;
    void paths(TreeNode*root){
        if(root->left==NULL&& root->right==NULL){
            int odd_count = 0,even_count=0,e=0;
            m[root->val]++;
            till++;
            for(auto it: m){
                if(it.second%2){
                    odd_count++;
                }
                else{
                    e++;
                    even_count+=(it.second);
                }
            }
            if(odd_count==1&&e==(m.size()-1)){
               
                ans++;
            }
            else if(odd_count==0&&e==(m.size())){
                ans++;
            }
            m[root->val]--;
            till--;
            return;
        }
        
        m[root->val]++;
        till++;
        
        if(root->left){
            paths(root->left);
        }
        if(root->right){
            paths(root->right);
        }
        m[root->val]--;
        till--;
        return;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        paths(root);
        return ans;
    }
};