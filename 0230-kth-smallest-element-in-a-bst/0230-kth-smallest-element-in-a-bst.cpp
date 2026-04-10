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
  void findkth(TreeNode* root,int k,int &count,int &ans){
    if(root==NULL){
      return ;
    }

    findkth(root->left,k,count,ans);
    count++;
    if(count==k){
      ans = root->val;
    }
    findkth(root->right,k,count,ans);
  }
public:
    int kthSmallest(TreeNode* root, int k) {
      int ans,count=0;
      findkth(root,k,count,ans);
      return ans;
       
        
    }
};