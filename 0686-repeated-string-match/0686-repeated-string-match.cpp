class Solution {
public:
    bool rabinKarp(string txt, string pat) {
        int n = txt.size();
        int m = pat.size();

        if (m > n)
            return false;

        int d = 256;
        int mod = 1e9 + 7;
        long long dm = 1;
        for (int i = 0; i < m - 1; ++i)
            dm = (dm * d) % mod;

        long long targetHash = 0;
        for (char ch : pat) {
            targetHash = (targetHash * d + ch) % mod;
        }

        long long currHash = 0;
        int l = 0;
        int r = 0;
        while (r < n) {

            if (r - l + 1 < m) {
                currHash = (currHash * d + txt[r]) % mod;
            }

            else if (r - l + 1 == m) {
                bool flag = false;
                for (int i = 0; i < m; ++i) {
                    if (txt[l + i] != pat[i]) {
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                    return true;

                currHash = (((currHash - txt[l] * dm + mod) % mod * d) % mod +
                            txt[r]) %
                           mod;
                l++;
            }
            r++;
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;

        string org = a;
        int cnt = 1;
        while (a.size() < b.size()) {
            a += org;
            cnt++;
        }

        if (rabinKarp(a, b))
            return cnt;
        if (rabinKarp(a + a, b))
            return cnt + 1;

        return -1;
    }
};