class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
            }
        }

        int ans = 0;
        vector<vector<int>> dirn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        while (!q.empty()) {
            vector<int> tp = q.front();
            q.pop();

            int i = tp[0];
            int j = tp[1];
            int t = tp[2];
            ans = max(t, ans);

            visited[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (isValid(ni, nj, m, n) && !visited[ni][nj] &&
                    grid[ni][nj] == 1) {
                    grid[ni][nj] = 2;
                    q.push({ni, nj, t + 1});
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};