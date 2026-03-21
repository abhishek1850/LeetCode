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
    vector<int> rightSideView(TreeNode* root) {
      if(root==NULL){
        return {};
      }

      queue<pair<TreeNode*,int>>q;
      map<int,int>mp;
      q.push({root,0});
      while(!q.empty()){
        pair<TreeNode*,int>p = q.front();
        q.pop();
        int x = p.second;
        TreeNode* n = p.first;
        if(mp.count(x)==0){
          mp[x]=n->val;
        }

        if(n->right!=NULL){
          q.push({n->right,x+1});
        }
        if(n->left!=NULL){
          q.push({n->left,x+1});
        }
      }
      vector<int>v;
      for(auto i : mp){
        v.push_back(i.second);
      }
      return v;

        
    }
};