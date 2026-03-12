class DSU {
public:
    vector<int> parent;
    vector<int> sizes;

    DSU(int n){
        parent.resize(n);
        sizes.resize(n);
        for (int i = 0; i < n; ++i){
            parent[i] = i;
            sizes[i] = 0;
        }
    }

    int findParent(int u){
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (sizes[pu] < sizes[pv]){
            parent[pu] = pv;
            sizes[pv] += sizes[pu]; 
        }
        else {
            parent[pv] = pu;
            sizes[pu] += sizes[pv];
        }
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> edges0, edges1;
        for (vector<int> &edge: edges){
            if (edge[3] == 0){
                edges0.push_back(edge);
            }
            else {
                edges1.push_back(edge);
            }
        }

        DSU dsu = DSU(n);

        vector<int> strengths0, strengths1;
        for (vector<int> &edge: edges1){
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];

            if (dsu.findParent(u) == dsu.findParent(v)) return -1;
            dsu.Union(u,v);
            strengths1.push_back(s);
        }

        sort(edges0.begin(), edges0.end(), [](vector<int> &a, vector<int> &b){
            return a[2] > b[2];
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        for (vector<int> &edge: edges0){
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];

            if (dsu.findParent(u) == dsu.findParent(v)) continue;
            dsu.Union(u,v);
            pq.push(s);
        }

        for (int i = 0; i < n; ++i){
            if (dsu.findParent(i) != dsu.findParent(0)) return -1;
        }

        for (int i = 0; i < k; ++i){
            if (pq.empty()) break;
            int tp = pq.top();
            pq.pop();
            strengths0.push_back(tp*2);
        }

        while (!pq.empty()){
            int tp = pq.top();
            pq.pop();
            strengths0.push_back(tp);
        }

        int mn0 = INT_MAX;
        int mn1 = INT_MAX;

        if (!strengths0.empty()) mn0 = *min_element(strengths0.begin(),strengths0.end());
        if (!strengths1.empty()) mn1 = *min_element(strengths1.begin(),strengths1.end());

        return min(mn0, mn1);
    }
};