#define ll long long

class DSU {
public:
    vector<ll> parent, sz;

    DSU(ll n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (ll i = 0; i < n; ++i)
            parent[i] = i;
    }

    ll findPar(ll u) {
        if (u == parent[u])
            return u;
        return parent[u] = findPar(parent[u]);
    }

    void Union(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);

        if (pu == pv)
            return;
        if (sz[pu] < sz[pv]) {
            parent[pu] = pv;
            sz[pv] += pu;
        } else {
            parent[pv] = pu;
            sz[pu] += pv;
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {

        DSU d(c + 1);
        for (vector<int>& uv : connections) {
            d.Union(uv[0], uv[1]);
        }

        vector<int> online(c + 1, true);
        unordered_map<int, set<int>> mp;
        for (int i = 1; i <= c; ++i) {
            mp[d.findPar(i)].insert(i);
        }

        vector<int> ans;

        for (vector<int>& ox : queries) {
            int op = ox[0];
            int x = ox[1];

            int px = d.findPar(x);
            if (op == 2) {
                online[x] = false;
                mp[px].erase(x);
            }
            else {
                if (online[x]) ans.push_back(x);
                else {
                    if (mp[px].empty()) ans.push_back(-1);
                    else ans.push_back(*mp[px].begin());
                }
            }
        }

        return ans;
    }
};