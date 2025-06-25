class DSU
{
public:
    vector<int> parent;
    vector<int> sz;

    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (sz[pu] < sz[pv])
        {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        }
        else
        {
            parent[pv] = pu;
            sz[pu] += sz[pv];
        }
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        DSU dsu(n * n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int node = i * n + j;
                if (grid[i][j] == 1)
                {
                    if (i + 1 < n && grid[i + 1][j] == 1)
                        dsu.Union(node, (i + 1) * n + j);

                    if (j + 1 < n && grid[i][j + 1] == 1)
                        dsu.Union(node, i * n + (j + 1));
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = *max_element(dsu.sz.begin(), dsu.sz.end());
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> parents;
                    for (auto &dir : dirs)
                    {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1)
                        {
                            parents.insert(dsu.findParent(ni * n + nj));
                        }
                    }

                    int curr = 1;
                    for (auto &p : parents)
                    {
                        curr += dsu.sz[p];
                    }

                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};