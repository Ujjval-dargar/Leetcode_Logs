class Solution {
public:

    bool check(int n, int k) {
        if (n == k) {
            return true;
        }
        if (k <= 0 || n < k) {
            return false;
        }

        return check(n / 10, k - n % 10) || 
               check(n / 100, k - n % 100) ||
               check(n / 1000, k - n % 1000);
    }

    int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            if (check(i * i, i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};
