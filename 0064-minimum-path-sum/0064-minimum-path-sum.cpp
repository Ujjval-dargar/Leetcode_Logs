class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = grid;

        for (int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = dp[i][n - 1] + dp[i + 1][n - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            dp[m - 1][i] = dp[m - 1][i] + dp[m - 1][i + 1];
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = dp[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};