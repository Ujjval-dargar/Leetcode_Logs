class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    cost[i][j] = 0;
            }
        }

        for (vector<int> i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            cost[u][v] = wt;
            cost[v][u] = wt;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (cost[i][k] == INT_MAX)
                    continue;
                for (int j = 0; j < n; ++j) {
                    if (cost[k][j] == INT_MAX)
                        continue;
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < n; ++j) {

                if (i!=j && cost[i][j] <= distanceThreshold)
                    ans[i]++;
            }

        }

        int res = 0;
        for (int i = 0; i < n; ++i) {

            if (ans[res] >= ans[i]) {
                res = i;
            }
        }

        return res;
    }
};