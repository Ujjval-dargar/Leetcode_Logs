class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1 = 1;
        int n = nums.size();
        int curr = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                curr++;
            else
                curr = 1;

            ans1 = max(curr, ans1);
        }

        curr = 1;
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                curr++;
            else
                curr = 1;

            ans1 = max(curr, ans1);
        }

        return ans1;
    }
};