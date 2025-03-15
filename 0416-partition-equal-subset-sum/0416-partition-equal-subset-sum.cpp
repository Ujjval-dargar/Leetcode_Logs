class Solution {
public:
    int targetSum(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        int n = nums.size();
        
        if (target == 0) {
            return true;
        }

        if (target < 0) {
            return false;
        }
        if (i == n) {
            return false;
        }
        
        if (dp[i][target] != -1)
            return dp[i][target];
        
        if (target >= nums[i]) {
            dp[i][target] = targetSum(nums, target - nums[i], i + 1, dp) ||
                             targetSum(nums, target, i + 1, dp);
        } else {
            dp[i][target] = targetSum(nums, target, i + 1, dp);
        }
        return dp[i][target];
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
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        
        return targetSum(nums, target, 0, dp) == 1;
    }
};
