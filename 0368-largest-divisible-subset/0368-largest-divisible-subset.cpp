class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> next(n, -1);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = 1 + dp[j];
                        next[i] = j;
                    }
                }
            }
        }

        int mxLen = 0;
        int strt = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > mxLen) {
                mxLen = dp[i];
                strt = i;
            }
        }

        vector<int> ans;
        while (strt != -1) {
            ans.push_back(nums[strt]);
            strt = next[strt];
        }

        return ans;
    }
};