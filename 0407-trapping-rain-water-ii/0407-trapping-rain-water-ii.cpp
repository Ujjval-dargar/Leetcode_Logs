class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        for (int i = 0; i < m; ++i) {
            visited[i][0] = 1;
            visited[i][n - 1] = 1;
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
        }

        for (int i = 0; i < n; ++i) {
            visited[0][i] = 1;
            visited[m - 1][i] = 1;
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[m - 1][i], m - 1, i});
        }

        int ans = 0;

        while (!pq.empty()) {
            int h = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            vector<vector<int>> dirn = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                    !visited[ni][nj]) {
                    visited[ni][nj] = 1;
                    ans += max(0, h - heightMap[ni][nj]);
                    pq.push({max(h, heightMap[ni][nj]), ni, nj});
                }
            }
        }

        return ans;
    }
};