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
                    temp[j + 1] = (temp[j + 1] + cnt[j]) % mod;
                } else {
                    temp[0] = (temp[0] + cnt[j]) % mod;
                    temp[1] = (temp[1] + cnt[j]) % mod;
                }
            }

            cnt = temp;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans % mod;
    }
};