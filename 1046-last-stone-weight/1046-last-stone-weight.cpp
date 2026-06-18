class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      if(stones.size()==1){
        return stones[0];
      }
      priority_queue<int>pq(stones.begin(),stones.end());
      while(pq.size()>1){
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if(x==y){
           pq.push(0);
          continue;
        }
        if(x!=y){
          y = y-x;
          pq.push(y);
        }
      }
      return pq.top();
        
    }
};