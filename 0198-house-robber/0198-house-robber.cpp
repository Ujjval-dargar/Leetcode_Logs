class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> dp(n,{-1,-1});
        dp[0]={0,nums[0]};
        for (int i=1;i<n;++i){
            dp[i]={max(dp[i-1].first,dp[i-1].second),nums[i]+dp[i-1].first};
        }

        return max(dp[n-1].first,dp[n-1].second);
    }
};