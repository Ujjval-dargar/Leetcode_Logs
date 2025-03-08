class Solution {
public:
    void dfs(int i, vector<vector<int>>& grid, vector<bool>& visited) {
        int n = grid.size();
        visited[i] = true;

        for (int j = 0; j < n; ++j) {
            if (i != j && grid[i][j] == 1 && !visited[j]) {
                dfs(j, grid, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ans++;
                dfs(i, grid, visited);
            }
        }

        return ans;
    }
};