class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq(amount.begin(), amount.end());
        int time = 0;
        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();

            if (first > 0) {
                first--;
                if(!pq.empty()){
                   int second = pq.top();
                   pq.pop();
                     if (second > 0) {
                        second--;
                     }
                     if (second > 0) {
                      pq.push(second);
                }

                }

                if (first > 0) {
                    pq.push(first);
                }
                 time++;
            }

           
        }

        return time;
    }
};