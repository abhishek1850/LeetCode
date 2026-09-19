class Solution {
    bool isPos(vector<vector<int>>& grid, int r, int c, int idx, int n) {
        if (r < 0 || c < 0 || c >= n || r >= n || grid[r][c] != idx) {
            return false;
        }
        return true;
    }
    bool solve(vector<vector<int>>& grid, int r, int c, int idx, int n) {

        if (!isPos(grid, r, c, idx, n)) {
            return false;
        }

        if (idx == n * n - 1) {
            return true;
        }

        if (solve(grid, r - 2, c + 1, idx + 1, n))
            return true;
        if (solve(grid, r - 2, c - 1, idx + 1, n))
            return true;
        if (solve(grid, r + 2, c + 1, idx + 1, n))
            return true;
        if (solve(grid, r + 2, c - 1, idx + 1, n))
            return true;
        if (solve(grid, r - 1, c + 2, idx + 1, n))
            return true;
        if (solve(grid, r - 1, c - 2, idx + 1, n))
            return true;
        if (solve(grid, r + 1, c + 2, idx + 1, n))
            return true;
        if (solve(grid, r + 1, c - 2, idx + 1, n))
            return true;

        return false;
    }

public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int idx = 0;
        return solve(grid, 0, 0, idx, n);
    }
};