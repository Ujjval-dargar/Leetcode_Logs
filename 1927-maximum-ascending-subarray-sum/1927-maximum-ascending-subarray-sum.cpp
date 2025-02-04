class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                curr += nums[0];
            } else {
                if (nums[i - 1] < nums[i]) {
                    curr += nums[i];
                } else {
                    curr = nums[i];
                }
            }

            ans = max(curr, ans);
        }
        return ans;
    }
};