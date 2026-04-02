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
  void helper(TreeNode* root,vector<string>& store,string s){
    if(root==NULL){
      return ;
    }
    s+=to_string(root->val);
    if(root->left==NULL && root->right==NULL){
      store.push_back(s);
      return ;
    }
    s+="->";
    helper(root->left,store,s);
    helper(root->right,store,s);
  }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      string s ="";
      vector<string>store;
      helper(root,store,s);
      return store;
        
    }
};