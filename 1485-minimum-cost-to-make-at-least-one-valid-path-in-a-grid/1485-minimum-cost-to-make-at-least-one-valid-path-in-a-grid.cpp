class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirn = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            int curr = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for (int k = 0; k < 4; ++k) {
                int new_i = i + dirn[k].first;
                int new_j = j + dirn[k].second;

                if (isValid(new_i, new_j, m, n)) {
                    int temp = 0;
                    if (grid[i][j] - 1 != k)
                        temp = 1;

                    int new_dist = curr + temp;

                    if (new_dist < dist[new_i][new_j]) {
                        dist[new_i][new_j] = new_dist;
                        pq.push({new_dist, {new_i, new_j}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};