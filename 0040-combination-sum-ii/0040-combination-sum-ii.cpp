class Solution {
  void solve(vector<int>& candidates, int target, vector<vector<int>>&ans,vector<int>&store,int sum,int index){
    if(sum==target){
      ans.push_back(store);
      return;
    }
    if(sum>target){
      return ;
    }

    for(int i =index;i<candidates.size();i++){
      if (i > index && candidates[i] == candidates[i - 1]){
    continue;
      }
      sum+=candidates[i];
      store.push_back(candidates[i]);
      solve(candidates,target,ans,store,sum,i+1);
      store.pop_back();
      sum-=candidates[i];
    }

  }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      vector<vector<int>>ans;
      
      vector<int>store;
      int sum = 0;
      int index = 0;
      solve(candidates,target,ans,store,sum,index);
      return ans;
        
    }
};