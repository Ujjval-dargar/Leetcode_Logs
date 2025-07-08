class Solution {
public:
    bool isVowel(char ch) {
        string vowels = "aeiou";
        for (char c : vowels) {
            if (ch == c)
                return true;
        }

        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size();

        int curr = 0;
        int mx = 0;

        int l = 0;
        int r = 0;
        while (r < n) {
            curr += isVowel(s[r]);

            while (l < r && r - l + 1 > k) {
                curr -= isVowel(s[l]);
                l++;
            }

            if (r - l + 1 == k) {
                mx = max(mx, curr);
            }

            r++;
        }

        return mx;
    }
};