class Solution {
public:
    int f1(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] == k) {
                ans = m;
                r = m - 1;
            } else if (nums[m] < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }

    int f2(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] == k) {
                ans = m;
                l = m + 1;
            } else if (nums[m] < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {f1(nums,target),f2(nums,target)};
    }
};