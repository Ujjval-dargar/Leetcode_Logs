class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp = matrix;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                } else if (j == n - 1) {
                    dp[i][j] = dp[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = dp[i][j] + min({dp[i - 1][j], dp[i - 1][j - 1],
                                               dp[i - 1][j + 1]});
                }
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};