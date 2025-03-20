class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void dsu(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            return parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {

        int e = edges.size();
        int q = query.size();

        dsu(n);

        for (int i = 0; i < e; ++i) {
            Union(edges[i][0], edges[i][1]);
        }

        vector<int> dp(n,-1);
        for (int i = 0; i < e; ++i) {
            int p = find(edges[i][0]);
            if (dp[p]==-1){
                dp[p]= edges[i][2];
            }
            dp[p] &= edges[i][2];
        }

        vector<int> ans;
        for (int i = 0; i < q; ++i) {
            int s = query[i][0];
            int e = query[i][1];

            if (find(s) != find(e)) {
                ans.push_back(-1);
            } else {
                ans.push_back(dp[find(s)]);
            }
        }

        return ans;
    }
};