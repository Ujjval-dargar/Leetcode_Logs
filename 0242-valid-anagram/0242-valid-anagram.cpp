class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m != n)
            return false;
        vector<int> a(26, 0);

        for (int i = 0; i < m; ++i) {
            a[s[i] - 'a']++;
        }

        for (int i = 0; i < n; ++i) {
            a[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (a[i] != 0) {
                return false;
            }
        }

        return true;
    }
};