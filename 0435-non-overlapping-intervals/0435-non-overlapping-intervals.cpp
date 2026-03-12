class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int count = 0;
        int currState = events[0][1];
        for (int i = 1; i < events.size(); i++) {
            if (events[i][0] >= currState) {
                currState = events[i][1];
            } else {
                count++;
            }
        }
        return count;
    }
};