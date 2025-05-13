class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;
        int n = s.size();

        vector<long long> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }

        for (int i = 0; i < t; ++i) {
            vector<long long> temp(26, 0);

            for (int j = 0; j < 26; ++j) {

                if (j != 25) {
                    temp[j + 1] = (temp[j + 1] % mod + cnt[j] % mod) % mod;
                } else {
                    temp[0] = (temp[0] % mod + cnt[j] % mod) % mod;
                    temp[1] = (temp[1] % mod + cnt[j] % mod) % mod;
                }
            }

            cnt = temp;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans % mod + cnt[i] % mod) % mod;
        }
        return ans % mod;
    }
};