class Solution {
public:
    bool check(vector<int>& bloomDay, int d, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int temp = 0;

            while (i < n && bloomDay[i] <= d) {
                temp++;
                if (temp == k) {
                    cnt++;
                    temp = 0;
                }
                i++;
            }
        }

        return cnt >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        long long req = 1LL * m * k;
        if (n < req) {
            return -1;
        }

        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int mn = *min_element(bloomDay.begin(), bloomDay.end());

        int l = mn;
        int r = mx;
        int ans = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (check(bloomDay, mid, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};