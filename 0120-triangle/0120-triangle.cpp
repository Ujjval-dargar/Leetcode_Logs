class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp = triangle;
        for (int i = 1; i < m; ++i) {
            int n = triangle[i].size();
            dp[i][0] = dp[i][0] + dp[i - 1][0];
            dp[i][n - 1] = dp[i][n - 1] + dp[i - 1][n - 2];
        }

        for (int i = 2; i < m; ++i) {
            int n = triangle[i].size();
            for (int j = 1; j < n - 1; ++j) {
                dp[i][j] = dp[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};