class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        int mod = 1e9 + 7;
        int src = 0;
        int dst = n - 1;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[src] = 0LL;
        ways[src] = 1;

        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> pq;
        pq.push({dist[src], src});

        while (!pq.empty()) {
            vector<long long> f = pq.top();
            pq.pop();

            long long curr = f[0];
            int u = f[1];
            int cnt = ways[u];

            if (curr > dist[u])
                continue;

            for (auto i : adj[u]) {
                int v = i.first;
                int w = i.second;

                if (dist[v] > (long long)w + curr) {
                    ways[v] = cnt;
                    dist[v] = w + curr;
                    pq.push({dist[v], v});
                } else if (dist[v] == w + curr) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[dst];
    }
};