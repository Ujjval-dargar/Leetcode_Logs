class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true; // Mark as visited when added to the queue

        int cnt = 0;
        vector<vector<int>> dirn = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            cnt += grid[x][y];

            for (const auto& d : dirn) {
                int ni = x + d[0];
                int nj = y + d[1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                    !visited[ni][nj] && grid[ni][nj] > 0) {
                    q.push({ni, nj});
                    visited[ni][nj] = true; // Mark as visited here
                }
            }
        }

        return cnt;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    ans = max(ans, bfs(grid, i, j, visited));
                }
            }
        }

        return ans;
    }
};
