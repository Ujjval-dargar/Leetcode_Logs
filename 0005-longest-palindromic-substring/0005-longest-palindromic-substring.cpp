class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j <= 1; ++j) {
                int low = i;
                int high = i + j;

                while (low >= 0 && high < n && s[low] == s[high]) {
                    if (maxLen < high - low + 1) {
                        maxLen = high - low + 1;
                        start = low;
                    }

                    low--;
                    high++;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};