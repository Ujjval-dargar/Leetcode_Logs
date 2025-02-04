class Solution {
public:
    int check(vector<int>& nums, int d) {
        int sum = 0;
        for (int i : nums) {
            sum += ceil((double)i / (double)d);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
        }

        int low = 1;
        int high = mx;

        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(nums, mid) <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};