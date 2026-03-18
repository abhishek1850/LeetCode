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
   void levelorder(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        vector<int> store;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                ans.push_back(store);
                while (!store.empty()) {
                    store.pop_back();
                }
                if (q.empty()) {
                    break;
                }
                q.push(NULL);
            } else {
                store.push_back(temp->val);
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>ans;
      levelorder(root,ans);
      int n = ans.size();
      for(int i = 0 ;i<n;i++){
        if(i%2!=0){
          reverse(ans[i].begin(), ans[i].end());
        }
      }
      return ans;
        
    }
};