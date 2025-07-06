class Solution {
public:
    void dfs(int u, int t, vector<vector<vector<int>>>& adj,
             vector<bool>& visited) {
        visited[u] = true;

        for (auto& vw : adj[u]) {
            int v = vw[0];
            int w = vw[1];

            if (!visited[v] && w > t) {
                dfs(v, t, adj, visited);
            }
        }
    }

    int numConnectedComp(vector<vector<vector<int>>>& adj, int t) {
        int n = adj.size();
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, t, adj, visited);
                cnt++;
            }
        }

        return cnt;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 0;

        vector<vector<vector<int>>> adj(n);
        for (vector<int>& uvw : edges) {
            adj[uvw[0]].push_back({uvw[1], uvw[2]});
            adj[uvw[1]].push_back({uvw[0], uvw[2]});
            high = max(high, uvw[2]);
        }

        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (numConnectedComp(adj, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};