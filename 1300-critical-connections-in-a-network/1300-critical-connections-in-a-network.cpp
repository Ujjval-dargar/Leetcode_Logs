class Solution {

private:
    vector<vector<int>> adj;
    vector<int> low;
    vector<int> arrTime;
    vector<int> visited;
    int time = 0;
    vector<vector<int>> bridges;

    void dfs(int u, int parent) {
        visited[u] = true;
        arrTime[u] = low[u] = time++;

        for (int v : adj[u]) {
            if (v == parent)
                continue;
            if (visited[v])
                low[u] = min(low[u], low[v]);
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > arrTime[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        adj.resize(n);
        low.resize(n, INT_MAX);
        arrTime.resize(n, INT_MAX);
        visited.resize(n, false);

        for (vector<int>& uv : connections) {
            int u = uv[0];
            int v = uv[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        return bridges;
    }
};