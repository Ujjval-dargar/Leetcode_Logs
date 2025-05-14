class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int curr = 0;
        int ans = 0;

        while (r < n) {
            curr += nums[r];

            while (l <= r && curr > k) {
                curr -= nums[l];
                l++;
            }

            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};