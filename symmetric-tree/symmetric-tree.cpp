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
    bool isSymmetric(TreeNode* root) {
        vector<int> t;
        vector<int> r;
       t= arr(root->left,t);
        r=arr2(root->right,r);
        if(t.size()!=r.size()){
            return false;
        }
        cout<<t.size()<<endl;
        for(int i=0;i<t.size();i++){
            cout<<t[i]<<"  "<<r[i]<<endl;
            if(t[i]!=r[i]){
                return false;
            }
        }
        return true;
    }
vector<int> arr(TreeNode* root,vector<int> &t){
        if(root==NULL){
            t.push_back(-1);
            return t;
        }
    arr(root->right,t);
    arr(root->left,t);
     t.push_back(root->val);
    return t;
    }
    vector<int> arr2(TreeNode* root,vector<int> &t){
        if(root==NULL){
            t.push_back(-1);
            return t;
        }
    arr2(root->left,t);
     arr2(root->right,t);
        t.push_back(root->val);
    return t;
    }
      };
   
