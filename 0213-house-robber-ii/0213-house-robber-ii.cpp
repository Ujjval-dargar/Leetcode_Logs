class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();

        int take = nums[0];
        int skip = 0;
        for (int i = 1; i < n; ++i) {
            int newTake = nums[i] + skip;
            int newSkip = max(take, skip);

            take = newTake;
            skip = newSkip;
        }

        return max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        return max(helper(nums1), helper(nums2));
    }
};