class Solution {
public:
    bool check(vector<int>& candies, long long k, long long m) {
        long long cnt = 0;
        int n = candies.size();
        for (int i = 0; i < n; ++i) {
            if (cnt >= k)
                return true;

            cnt += candies[i] / m;
        }
        return (cnt >= k);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int mx = candies[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, candies[i]);
        }

        int l = 1;
        int r = mx;
        int ans = 0;

        while (l <= r) {
            int mid = ceil((double)(l + r) / 2.0);

            if (check(candies, k, mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};