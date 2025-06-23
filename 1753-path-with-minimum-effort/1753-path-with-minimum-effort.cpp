class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        vector<vector<int>> dirn = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            vector<int> tp = pq.top();
            pq.pop();

            int curr = tp[0];
            int i = tp[1];
            int j = tp[2];

            if (curr > dist[i][j])
                continue;

            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (ni < 0 || nj < 0 || ni >= r || nj >= c)
                    continue;

                int cost = max(curr, abs(heights[ni][nj] - heights[i][j]));

                if (dist[ni][nj] > cost) {
                    dist[ni][nj] = cost;
                    pq.push({dist[ni][nj], ni, nj});
                }
            }
        }

        return dist[r - 1][c - 1];
    }
};