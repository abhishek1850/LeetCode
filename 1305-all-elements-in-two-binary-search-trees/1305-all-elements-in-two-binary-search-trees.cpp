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
  void getInorder(TreeNode* root,vector<int>&s){
    if(root==NULL){
      return ;
    }
    getInorder(root->left,s);
    s.push_back(root->val);
    getInorder(root->right,s);
  }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector<int>s1;
      vector<int>s2;
      vector<int>finalS;

      getInorder(root1,s1);
      getInorder(root2,s2);

      int i=0,j=0;
      while(i<s1.size() && j<s2.size()){
        if(s1[i]<s2[j]){
          finalS.push_back(s1[i++]);
        }
        else{
          finalS.push_back(s2[j++]);
        }
      }

      while(i<s1.size()){
        finalS.push_back(s1[i++]);
      }
      while(j<s2.size()){
        finalS.push_back(s2[j++]);
      }
      return finalS;


        
    }
};