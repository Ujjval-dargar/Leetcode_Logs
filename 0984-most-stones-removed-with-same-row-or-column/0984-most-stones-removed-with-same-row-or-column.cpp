class dsu {
public:
    vector<int> parent;
    vector<int> sz;

    dsu(int n) {
        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    // by size
    void Union(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;
        if (sz[pu] < sz[pv]) {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        } else {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        dsu d(n);
        unordered_map<int, int> row2idx;
        unordered_map<int, int> col2idx;

        for (int i = 0; i < n; ++i) {

            int r = stones[i][0];
            int c = stones[i][1];

            if (row2idx.count(r)) {
                d.Union(i, row2idx[r]);
            } else {
                row2idx[r] = i;
            }

            if (col2idx.count(c)) {
                d.Union(i, col2idx[c]);
            } else {
                col2idx[c] = i;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (d.findParent(i) == i)
                cnt++;
        }

        return n - cnt;
    }
};