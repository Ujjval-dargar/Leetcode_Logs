class Solution {
public:
    bool check(vector<int>& weights, int cap, int days) {
        int n = weights.size();
        int curr = 0;
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            if (weights[i] > cap) {
                return false;
            }
            if (curr + weights[i] > cap) {
                curr = weights[i];
                temp++;
            } else if (curr + weights[i] == cap) {
                curr = 0;
                temp++;
            } else {
                curr += weights[i];
            }
        }

        if (curr > 0) {
            temp++;
        }

        return temp <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += weights[i];
        }

        int l = 1;
        int r = sum;
        int ans = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (check(weights, mid, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << endl;
        cout << endl;
        cout << check(weights, 2, 4) << endl;
        return ans;
    }
};