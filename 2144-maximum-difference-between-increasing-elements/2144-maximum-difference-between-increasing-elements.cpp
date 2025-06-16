class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n, -1);
        temp[n - 1] = -1;
        temp[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; --i) {
            temp[i] = max(nums[i + 1], temp[i + 1]);
        }

        int ans = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (temp[i] > nums[i]) {
                ans = max(ans, temp[i] - nums[i]);
            }
        }

        return ans;
    }
};