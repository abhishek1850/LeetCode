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
  void inorder(TreeNode* r,vector<int>&v){
    if(r==NULL){
      return;
    }
    inorder(r->left,v);
    v.push_back(r->val);
    inorder(r->right,v);
  }

  TreeNode* balanceBSTBuild(vector<int>v,int s,int e){
    if(s>e){
      return NULL;
    }
    int mid = s + (e-s)/2;
    TreeNode* curr = new TreeNode(v[mid]);
    curr->left = balanceBSTBuild(v,s,mid-1);
    curr->right = balanceBSTBuild(v,mid+1,e);
    return curr;


  }
public:
    TreeNode* balanceBST(TreeNode* root) {
      vector<int>v;
      inorder(root,v);
      int n = v.size()-1;
      return balanceBSTBuild(v,0,n);
        
    }
};