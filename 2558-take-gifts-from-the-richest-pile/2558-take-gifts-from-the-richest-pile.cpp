class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
      priority_queue<int>pq(gifts.begin(),gifts.end());
      long long ans=0;

      while(k--){
        int val = pq.top();
        pq.pop();
        val = floor(sqrt(val));
        pq.push(val);
      }

      while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
      }
      return ans;

        
    }
};