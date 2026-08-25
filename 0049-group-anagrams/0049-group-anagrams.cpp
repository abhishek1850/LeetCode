class Solution {

  bool count(vector<int>&s,string str){
    for(auto i : str){
      s[i-'a']++;
    }
    return true;
  }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<vector<int>,vector<string>>mp; 
      for(auto i:strs){
        vector<int>freq(26,0);
        count(freq,i);
        mp[freq].push_back(i);
      }

      vector<vector<string>>ans;
      for(auto i:mp){
        ans.push_back(i.second);
      }
      return ans;
        
    }
};