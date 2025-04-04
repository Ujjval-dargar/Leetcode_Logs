class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp = matrix;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                int t = INT_MAX;
                if (j - 1 >= 0) {
                    t = min(t, dp[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    t = min(t, dp[i - 1][j + 1]);
                }

                dp[i][j] = matrix[i][j] + min(dp[i - 1][j], t);
            }
        }

        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};