class Solution {
public:
    int expand(string& s, int l, int r) {
        int n = s.size();
        int ans = 0;
        while (l >= 0 && r < n && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }

        return ans;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += expand(s, i, i) + expand(s, i, i + 1);
        }

        return ans;
    }
};