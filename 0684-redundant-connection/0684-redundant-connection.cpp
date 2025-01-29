class Solution {
public:
    vector<int> parent;
    vector<int> size;

    void DSU(int n) {
        parent.resize(n + 1, -1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    bool Union(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        else {
            if (size[u] <= size[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU(n);
        for (int i = 0; i < n; ++i) {
            if (!Union(edges[i][0], edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            }
        }

        return {};
    }
};