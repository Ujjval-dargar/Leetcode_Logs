class Solution {
public:
    bool rabinKarp(string txt, string pat) {
        int n = txt.size();
        int m = pat.size();
        if (m > n) return false;

        long long d   = 256;
        long long mod = 1000000007;
        
        long long dm = 1;
        for (int i = 0; i < m; ++i)
            dm = (dm * d) % mod;

        long long targetHash = 0;
        for (unsigned char ch : pat)
            targetHash = (targetHash * d + ch) % mod;

        long long currHash = 0;
        int l = 0, r = 0;
        while (r < n) {
            
            currHash = (currHash * d + txt[r]) % mod;

            if (r - l + 1 > m) {
                currHash = (
                    currHash
                    - (long long)txt[l] * dm % mod
                    + mod
                ) % mod;
                l++;
            }
            if (r - l + 1 == m) {
                if (currHash == targetHash) {
                    bool match = true;
                    for (int i = 0; i < m; ++i) {
                        if (txt[l + i] != pat[i]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) return true;
                }
            }

            r++;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1;
        string org = a;
        int cnt = 1;
        while (a.size() < b.size()) {
            a += org;
            cnt++;
        }
        if (rabinKarp(a, b))         return cnt;
        if (rabinKarp(a + org, b))   return cnt + 1;
        return -1;
    }
};
