class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      // for(auto i:strs){
      //   if(i.empty()){
      //     return "";
      //   }
      // }
      // string store=strs[0];

      // for(int i =1;i<strs.size();i++){
      //   string str = strs[i];
      //   int n = str.size();

      //   for(int i =0;i<n;i++){
      //     if(store.size()>n){
      //       store.resize(n);
      //     }
      //     if(store[i]!=str[i]){
      //       store.resize(i);
      //       break;
      //     }
      //   }
        
      // }

      // return store;

      string store = strs[0];
      for(int i =1;i<strs.size();i++){
        int len = min(store.size(),strs[i].size());
        string s = strs[i];
        int l =0;
        while(store[l]==s[l] && l<len){
          l++;
        }

        store.resize(l);
        if(store.empty()){
          return "";

      }
      }

      return store;



        
    }
};