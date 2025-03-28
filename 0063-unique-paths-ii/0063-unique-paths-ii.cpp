class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]==1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
            if (obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
                break;
            }
                

        }

        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
            if (obstacleGrid[i][0] == 1){
                dp[i][0] = 0;
                break;
            }
               
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
            }
        }

        return dp[m - 1][n - 1];
    }
};