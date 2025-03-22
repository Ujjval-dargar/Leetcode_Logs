class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> edgeCount;

    void DSU(int n) {
        parent.resize(n);
        size.resize(n);
        edgeCount.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
            edgeCount[i] = 0;
        }
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v) {
            edgeCount[u]++;
            return;
        }

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
            edgeCount[v] += edgeCount[u] + 1;
        } else {
            parent[v] = u;
            size[u] += size[v];
            edgeCount[u] += edgeCount[v] + 1;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU(n);
        for (auto edge : edges) {
            Union(edge[0], edge[1]);
        }

        int ans = 0;
        vector<int> done(n, false);
        for (int i = 0; i < n; ++i) {
            int p = findParent(i);
            if (!done[p]) {
                done[p] = true;
                int c = size[p];
                int e = edgeCount[p];
                ans += ((e == (c * (c - 1)) / 2) ? 1 : 0);
            }
        }

        return ans;
    }
};