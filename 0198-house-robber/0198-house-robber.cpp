class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n);

        dp[0] = {0,nums[0]};
        for (int i=1;i<n;++i){

            if (i>=2) dp[i] = {max(dp[i-1][0],dp[i-1][1]), nums[i] + max(dp[i-2][0],dp[i-2][1])};
            else dp[i] = {max(dp[i-1][0],dp[i-1][1]), nums[i]};
        }

        return max(dp[n-1][0],dp[n-1][1]);
    }

};