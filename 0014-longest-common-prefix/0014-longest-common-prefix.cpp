class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      for(auto i:strs){
        if(i.empty()){
          return "";
        }
      }
      string store=strs[0];

      for(int i =1;i<strs.size();i++){
        string str = strs[i];
        int n = str.size();

        for(int i =0;i<n;i++){
          if(store.size()>n){
            store.resize(n);
          }
          if(store[i]!=str[i]){
            store.resize(i);
            break;
          }
        }
        
      }

      return store;



        
    }
};