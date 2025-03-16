#define ll long long

class Solution {
public:
    bool check(vector<int>& ranks, ll cars, ll mid) {
        ll cnt = 0LL;
        int n = ranks.size();

        for (int i = 0; i < n; ++i) {
            cnt += sqrt(mid / ranks[i]);
        }

        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll mn = *min_element(ranks.begin(), ranks.end());
        ll mx = *max_element(ranks.begin(), ranks.end());

        ll low = 0;
        ll high = mn * cars * cars;
        ll ans = high;

        while (low <= high) {
            ll mid = (low + high) / 2;

            if (check(ranks, cars, mid)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};