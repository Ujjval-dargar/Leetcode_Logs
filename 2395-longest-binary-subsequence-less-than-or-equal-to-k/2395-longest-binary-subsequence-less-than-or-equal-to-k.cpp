class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();

        int power = 0;
        int ans = 0;
        long long val = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ans++;
            } else {

                if (power < 32 && (val + (1LL << power)) <= k) {
                    val = (1LL << power) + val;
                    ans++;
                }
            }
            power++;
        }

        return ans;
    }
};