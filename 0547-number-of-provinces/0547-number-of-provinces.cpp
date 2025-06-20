class Solution {
public:
    void dfs(vector<vector<int>>& grid, int u, vector<bool>& visited) {
        int n = grid.size();

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (grid[u][v] == 1 && !visited[v])
                dfs(grid, v, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<bool> visited(n, false);
        for (int u = 0; u < n; ++u) {
            if (!visited[u]) {
                ans++;
                dfs(grid, u, visited);
            }
        }

        return ans;
    }
};