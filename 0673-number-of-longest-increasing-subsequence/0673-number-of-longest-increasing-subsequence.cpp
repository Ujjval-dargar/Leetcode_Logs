class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {

                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    } else if (dp[i] == 1 + dp[j]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int mx = *max_element(dp.begin(), dp.end());

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (mx == dp[i]) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};