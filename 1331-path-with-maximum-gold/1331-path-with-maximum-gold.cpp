class Solution {
public:
    vector<vector<int>> dirn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        int curr = grid[i][j];
        grid[i][j] = 0;

        int mx = curr;

        for (vector<int>& dir : dirn) {
            mx = max(mx, curr + dfs(grid, i + dir[0], j + dir[1], m, n));
        }

        grid[i][j] = curr;

        return mx;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0)
                    ans = max(ans, dfs(grid, i, j, m, n));
            }
        }

        return ans;
    }
};