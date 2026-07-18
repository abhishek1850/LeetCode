class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // unordered_map<char, int> frq;
        // for (char c : tasks)
        //     frq[c]++;
        // priority_queue<int> pq;
        // for (auto& p : frq)
        //     pq.push(p.second);

        // int time = 0;

        // while (!pq.empty()) {
        //     vector<int> temp;
        //     for (int i = 0; i <= n; i++) {
        //         if (!pq.empty()) {
        //             int cnt = pq.top();
        //             pq.pop();
        //             if (cnt - 1 > 0) {
        //                 temp.push_back(cnt - 1);
        //             }
        //             time++;
        //         } else if (!temp.empty() || !pq.empty()) {
        //             time++;
        //         }
        //     }

        //     for (int c : temp)
        //         pq.push(c);
        // }
        // return time;

        int time = 0;
        vector<int> frq(26, 0);
        for (auto c : tasks) {
            frq[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (frq[i] > 0) {
                pq.push(frq[i]);
            }
        }

        while (!pq.empty()) {
            vector<int> temp;
            int slotUsed = 0;
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int count = pq.top();
                    pq.pop();
                    count--;
                    slotUsed++;
                    if (count > 0) {
                        temp.push_back(count);
                    }
                }
            }

            for (int val : temp)
                pq.push(val);
            time += pq.empty() ? slotUsed : n + 1;
        }
        return time;
    }
}

;