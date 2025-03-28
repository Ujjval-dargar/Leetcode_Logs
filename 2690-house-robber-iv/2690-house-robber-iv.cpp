class Solution {
public:
    bool check(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= m) {
                cnt++;
                i++;
            }

            if (cnt>=k) return true;
        }

        return (cnt >= k);
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        int low = mn;
        int high = mx;
        int ans = mx;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};