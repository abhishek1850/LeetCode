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
   TreeNode* buildTree(vector<int>& num, int s, int e){
    if(s>e){
      return NULL;
    }
    int  mid = s + (e-s)/2;
    TreeNode* curr = new TreeNode(num[mid]);
    curr->left = buildTree(num,s,mid-1);
    curr->right = buildTree(num,mid+1,e);
    return curr;
   }
    
  
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return buildTree(nums,0,nums.size()-1);   
    }
};