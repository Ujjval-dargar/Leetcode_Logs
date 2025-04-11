class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            string s = to_string(i);
            int n = s.size();
            if (n % 2 == 1) {
                continue;
            }
            int sum1 = 0;
            int sum2 = 0;
            for (int i = 0; i < n / 2; ++i) {
                sum1 += s[i] - '0';
            }
            for (int i = n / 2; i < n; ++i) {
                sum2 += s[i] - '0';
            }

            if (sum1 == sum2)
                ans++;
        }

        return ans;
    }
};