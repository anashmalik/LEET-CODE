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
    bool isValidBST(TreeNode* root) {
        vector<int> t;
        t=arr(root,t);
        for(int i=0;i<t.size()-1;i++){
          //  cout<<t[i]<<"   jdsahflkhaja"<<endl;
            if(t[i]>=t[i+1]){
                return false;
            }
        }
        return true;
        
    }
    vector<int> arr(TreeNode* root,vector<int> &t){
        if(root==NULL){
            return t;
        }
    arr(root->left,t);
    t.push_back(root->val);
     arr(root->right,t);
    return t;
    }
};