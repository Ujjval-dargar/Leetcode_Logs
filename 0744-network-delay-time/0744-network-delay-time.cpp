class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int>& i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            vector<int> tp = pq.top();
            pq.pop();

            int curr = tp[0];
            int u = tp[1];

            if (curr > dist[u])
                continue;

            for (auto i : adj[u]) {
                int v = i.first;
                int w = i.second;

                if (dist[v] > w + curr) {
                    dist[v] = w + curr;
                    pq.push({dist[v], v});
                }
            }
        }

        int mx = *max_element(dist.begin() + 1, dist.end());
        return mx == INT_MAX ? -1 : mx;
    }
};