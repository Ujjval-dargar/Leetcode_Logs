class Solution {
public:
    int lower_bound(vector<int>& arr, int k) {
        int n = arr.size();
        int r = n - 1;
        int l = 0;
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (arr[mid] >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int maximumCount(vector<int>& nums) {

        int n = nums.size();
        int neg = lower_bound(nums, 0);
        int pos = n - lower_bound(nums, 1);

        if (pos == n + 1 && neg == -1 ){
            return n;
        }
        else if (pos == n + 1) {
            return neg;
        }

        return max(neg, pos);
    }
};