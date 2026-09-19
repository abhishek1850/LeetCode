class Solution {
  bool isPal(string s){
    int ss =0;
    int e = s.size()-1;
    while(ss<e){
      if(s[ss]!=s[e]){
        return false;
      }
      ss++;
      e--;
    }
    return true;
  }
  void solve(string s,vector<vector<string>>&ans,vector<string>&store,int index,string substr){
    if(index==s.size()){
      ans.push_back(store);
      return ;
    }

    for(int i=index ;i<s.size();i++){
      substr = s.substr(index,i-index+1);
      if(isPal(substr)){
        store.push_back(substr);
        solve(s,ans,store,i+1,substr);
        store.pop_back();
      }
      

    }

  }
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>>ans;
      vector<string>store;
      int index = 0;
      string substr = "";
      solve(s,ans,store,index,substr);
      return ans;
        
    }
};