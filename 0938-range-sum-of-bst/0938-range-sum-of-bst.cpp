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
    int rangeSumBST(TreeNode* root, int low, int high) {
      if(root==NULL ){
        return 0;
      }
      // int left = rangeSumBST(root->left,low,high);
      // int right = rangeSumBST(root->right,low,high);

      // if(root->val>=low && root->val<=high){
      //   return left+right+root->val;
      // }
      // return left+right; 

      if(root->val>=low && root->val<=high){
        int left = rangeSumBST(root->left,low,high);
        int right =rangeSumBST(root->right,low,high);
        return root->val+left+right;
      }
      else if(root->val<=low){
        return rangeSumBST(root->right,low,high);
      }
      else if(root->val>=high){
        return rangeSumBST(root->left,low,high);
      }
      return root->val;
    }
};