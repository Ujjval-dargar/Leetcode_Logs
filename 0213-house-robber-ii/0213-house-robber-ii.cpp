class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n==1){
            return nums[0];
        }

        vector<pair<int, int>> dp1(n, {-1, -1});
        vector<pair<int, int>> dp2(n, {-1, -1});

        dp1[0] = {0, nums[0]};
        for (int i = 1; i < n - 1; ++i) {
            dp1[i] = {max(dp1[i - 1].first, dp1[i - 1].second),
                      nums[i] + dp1[i - 1].first};
        }

        dp2[1] = {0, nums[1]};
        for (int i = 2; i < n; ++i) {
            dp2[i] = {max(dp2[i - 1].first, dp2[i - 1].second),
                      nums[i] + dp2[i - 1].first};
        }

        return max(max(dp1[n - 2].first, dp1[n - 2].second),
                   max(dp2[n - 1].first, dp2[n - 1].second));
    }
};