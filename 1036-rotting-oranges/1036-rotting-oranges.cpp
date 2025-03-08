class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();

            int i = p.first.first;
            int j = p.first.second;
            int t = p.second;

            visited[i][j] = true;

            vector<vector<int>> dirn = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (ni < m && nj < n && ni >= 0 && nj >= 0 &&
                    !visited[ni][nj] && grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    q.push({{ni, nj}, t + 1});
                    ans = max(ans, t + 1);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};