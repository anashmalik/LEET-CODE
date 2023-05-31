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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> a;
        if(!root) return a;
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode*,int> p;
        p.first=root;
        p.second=0;
        int k=0;    
        q.push(p);
        while(!q.empty()){
            p=q.front();
            TreeNode* r =p.first;
            int j=p.second;
            q.pop();
            if(j>=k){
                vector<int> b;
                b.push_back(r->val);
                a.push_back(b);
                k++;
            }
            else{
                a[j].push_back(r->val);
            }
            
            
            if(r->left){
                p.first=r->left;
                p.second=j+1;
                q.push(p);
            }
            if(r->right){
                p.first=r->right;
                p.second=j+1;
                q.push(p);
            }
        }
        return a;
        
    }
};