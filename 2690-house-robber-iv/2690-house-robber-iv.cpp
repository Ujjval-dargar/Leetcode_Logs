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
            
        }

        return (cnt >= k);
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        int low = 1;
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