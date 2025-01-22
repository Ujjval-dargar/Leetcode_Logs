class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<vector<int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({0, i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int curr = q.front()[0];
            int i = q.front()[1];
            int j = q.front()[2];
            q.pop();

            vector<vector<int>> dirn = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int k = 0; k < 4; ++k) {
                int r = i + dirn[k][0];
                int c = j + dirn[k][1];

                if (r < m && c < n && r >= 0 && c >= 0 && !visited[r][c]) {
                    ans[r][c] = 1 + curr;
                    visited[r][c] = true;
                    q.push({ans[r][c], r, c});
                }
            }
        }

        return ans;
    }
};