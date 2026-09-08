class Solution {
    bool ifPos(int n, vector<int> quantities, int mid) {
        int stores = 0;
        for (int i : quantities) {
            stores += (i + mid - 1) / mid; // ( ceil ( (double) i / mid))
            if (stores > n) {
                return false;
            }
        }
        return true;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1;
        int e = *max_element(quantities.begin(), quantities.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ifPos(n, quantities, mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};