class Solution {
public:
    bool targetSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));

        for (int i = 1; i <= target; ++i) {
            dp[0][i] = false;
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i-1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= target; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        return targetSum(nums, target);
    }
};
