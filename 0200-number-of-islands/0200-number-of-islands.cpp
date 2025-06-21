class Solution {
public:
    vector<vector<int>> dirn = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = true;

        for (int k = 0; k < 4; ++k) {
            int ni = i + dirn[k][0];
            int nj = j + dirn[k][1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj] &&
                grid[ni][nj] == '1') {
                dfs(ni, nj, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return ans;
    }
};