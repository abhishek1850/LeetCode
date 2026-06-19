class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char,int>mp;
      for(char c:s){
        mp[c]++;
      }
      priority_queue<pair<int,char>>pq;

      for(auto &i:mp){
        pq.push({i.second,i.first});
      }

      string store= "";
      while(!pq.empty()){
        int val = pq.top().first;
        while(val--){
           
          store.push_back(pq.top().second);
        }
        pq.pop();
      }

      return store;
        
    }
};