class Solution {
public:
    int check(vector<int>& nums, int d) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += ceil((double)nums[i] / (double)d);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;
        int high = 1e6;

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