class Solution {
public:

    int helper(vector<int>& nums, int i, bool prev, vector<vector<int>>& dp) {
    int n = nums.size();
    if (i == n) {
        return 0;
    }
    
    int state = prev ? 1 : 0;
    
    if (dp[i][state] != -1) {
        return dp[i][state];
    }
    
    if (prev) {
        dp[i][state] = helper(nums, i + 1, false, dp);
    }
    else {
        dp[i][state] = max(nums[i] + helper(nums, i + 1, true, dp),
                           helper(nums, i + 1, false, dp));
    }
    
    return dp[i][state];
}

int rob(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return helper(nums, 0, false, dp);
}

};