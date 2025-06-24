
class DSU {
public:
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        int e = connections.size();
        if (e<n-1) return -1;

        DSU d(n);
        for (vector<int>& edge : connections) {
            d.Union(edge[0], edge[1]);
        }

        int cnt = 0;
        for (int i=0;i<n;++i){
            if (d.findParent(i)==i){
                cnt++;
            }
        }

        return cnt-1;

        
    }
};