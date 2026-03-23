/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

//   bool rootToNodePath(TreeNode* root,TreeNode* p,vector<int>&path){
//     if(root==NULL){
//       return false;
//     }

//     path.push_back(root->val);
//     if(root==p){
//       return true;
//     }

//     int left = rootToNodePath(root->left,p,path);
//     int right = rootToNodePath(root->right,p,path);
//     if(left || right){
//       return true;
//     }
//     path.pop_back();
//     return false;
//   }
public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//       if(root==NULL){
//         return NULL;
//       }

//       vector<int>path1;
//       vector<int>path2;

//       rootToNodePath(root,p,path1);
//       rootToNodePath(root,q,path2);

//       int lca = -1;
//       for(int i = 0,j=0;i<path1.size()&& j<path2.size();i++,j++){
//       if(path1[i]!=path2[j]){
//         TreeNode* newNode = new TreeNode(lca);
//         return newNode;
//       }
      
//       lca=path1[i]; 
//       }
//       TreeNode* newNode = new TreeNode(lca);
//       return newNode;
//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root ==NULL || root==p || root == q){
        return root;
      }
     
      TreeNode* left = lowestCommonAncestor(root->left,p,q);
      TreeNode* right = lowestCommonAncestor(root->right,p,q);

      if(left && right){
        return root;
      }
      return !left?right:left;

    }

    
};