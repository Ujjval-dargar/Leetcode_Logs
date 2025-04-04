class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n);
        vector<int> next(n, -1);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    next[i] = j;
                }
            }
        }

        int strt = -1;
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > mx) {
                mx = dp[i];
                strt = i;
            }
        }

        vector<int> ans;
        while (strt != -1){
            ans.push_back(nums[strt]);
            strt = next[strt];
        }

        return ans;
    }
};