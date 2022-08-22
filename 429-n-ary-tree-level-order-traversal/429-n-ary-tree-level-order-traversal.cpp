/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>ret;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            vector<vector<int>>v({});
            return v;
        }
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int>v;
            while(sz--){
                Node*r = q.front();
                q.pop();
                
                v.push_back(r->val);
                
                for(auto it : r->children){
                    q.push(it);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};