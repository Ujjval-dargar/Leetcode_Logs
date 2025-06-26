class Solution {
public:
    vector<int> computeLPS(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < n) {
            if (s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            }

            else {
                if (len > 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> lps = computeLPS(needle);

        int i = 0;
        int j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - m;
            } else if (i < n && haystack[i] != needle[j]) {
                if (j - 1 >= 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};