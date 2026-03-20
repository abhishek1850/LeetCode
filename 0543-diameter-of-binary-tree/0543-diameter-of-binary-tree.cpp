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

    // int height(TreeNode* root){
    //   if(root==NULL){
    //     return 0;
    //   }
    //   int left = height(root->left);
    //   int right = height(root->right);
    //   int curr = max(left,right)+1;
    //   return curr;
    // }


    // int diameterOfBinaryTree(TreeNode* root) {
    //   if(root==NULL){
    //     return 0;
    //   }
    //   int curr = height(root->left)+height(root->right);
    //   int left = diameterOfBinaryTree(root->left);
    //   int right = diameterOfBinaryTree(root->right);
    //   return max(curr,max(left,right));
        
    // }

    pair<int,int>diameter(TreeNode* root){
      if(root==NULL){
        return {0,0};
      }

      pair<int,int>leftInfo = diameter(root->left);
      pair<int,int>rightInfo = diameter(root->right);
      int currD = leftInfo.second + rightInfo.second ;
      int finalD = max(currD, max(leftInfo.first,rightInfo.first));
      int finalH = max(leftInfo.second,rightInfo.second)+1;
      return make_pair(finalD,finalH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
      return diameter(root).first;
    }
};