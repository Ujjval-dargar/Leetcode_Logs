class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int>& i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<vector<int>> q; // stop node dist

        dist[src] = 0;
        q.push({0, src, 0});

        while (!q.empty()) {
            vector<int> f = q.front();
            q.pop();

            int stop = f[0];
            int u = f[1];
            int curr = f[2];

            if (stop > k)
                continue;

            for (auto i : adj[u]) {
                int v = i.first;
                int w = i.second;

                if (w + curr < dist[v] && stop <= k) {
                    dist[v] = w + curr;
                    q.push({stop + 1, v, dist[v]});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};