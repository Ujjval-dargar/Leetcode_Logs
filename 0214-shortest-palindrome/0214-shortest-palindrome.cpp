class Solution {
public:
    int longestPrefixPalindrome(string s) {
        string t = s + '#' + string(s.rbegin(), s.rend());
        int n = t.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;
        while (i < n) {
            if (t[i] == t[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len - 1 >= 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        return lps.back();
    }

    string shortestPalindrome(string s) {
        int n = s.size();

        int toadd = n - longestPrefixPalindrome(s);

        string t = s.substr(n - toadd);
        reverse(t.begin(),t.end());

        return t + s;
    }
};