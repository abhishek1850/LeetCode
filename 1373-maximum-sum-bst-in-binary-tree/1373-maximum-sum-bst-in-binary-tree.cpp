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

  class Info{
  public:
  bool isBST;
  int min;
  int max;
  int sum;
  Info(bool isBST,int min,int max,int sum){
    this->isBST =isBST;
    this->min = min;
    this->max = max;
    this->sum = sum;
  }
};

int maxSum=0;
Info* largestBST(TreeNode* root){
    if(root==NULL){
        return new Info(true,INT_MAX,INT_MIN,0);
    }
    // if(root==NULL){
    //     return NULL;
    // }
    // if(root->left ==NULL && root->right ==NULL){
    //     return new Info(true,root->data,root->data,1);
    // }

    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);
    int currMin = min(root->val,min(leftInfo->min,rightInfo->min));
    int currMax = max(root->val,max(leftInfo->max,rightInfo->max));
    int currSum = leftInfo->sum+rightInfo->sum+root->val;
    if(leftInfo->isBST && rightInfo->isBST
    && root->val>leftInfo->max
    && root->val<rightInfo->min
    ){
        maxSum = max(maxSum,currSum);
        return new Info(true,currMin,currMax,currSum);
    }
    return new Info(false,currMin,currMax,currSum);
}
    

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        largestBST(root);
        return maxSum;
    }
};