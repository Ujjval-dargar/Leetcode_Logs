class Solution {
public:
    bool check(vector<int>& piles, int h, int s) {
        int curr = 0;
        int n = piles.size();
        for (int i = 0; i < n; ++i) {
            curr += ceil((double)piles[i] / (double)s);
            if (curr > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, piles[i]);
        }

        int low = 1;
        int high = mx;
        int res = -1;

        while (low <= high) {
            int mid = (high - low) / 2 + low;

            if (check(piles, h, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};