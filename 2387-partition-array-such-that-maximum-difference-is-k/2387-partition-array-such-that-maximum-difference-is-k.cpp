class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] - nums[i] <= k)
                continue;
            else {
                ans++;
                i = j;
            }
        }

        return ans + 1;
    }
};