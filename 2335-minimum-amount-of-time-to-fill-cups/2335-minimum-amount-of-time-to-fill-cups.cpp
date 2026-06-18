class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        if(pq.top()==0){
          return 0;
        }
        int time = 0;
        while (pq.size()>=2) {
          int first = pq.top();
          first--;
          pq.pop();
          int second = pq.top();
          second--;
          pq.pop();

          time++;

          if(first>0) pq.push(first);
          if(second>0) pq.push(second);  
        }

        return pq.empty()?time:pq.top()+time;
    }
};