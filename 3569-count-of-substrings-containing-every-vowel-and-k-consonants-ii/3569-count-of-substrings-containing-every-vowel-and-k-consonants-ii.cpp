
class Solution {
public:

    long long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k + 1);
    }

    long long helper(string word, int k) {

        long long n = word.size();

        long long l = 0;
        long long r = 0;

        unordered_map<char, long long> found;
        found['a'] = 0;
        found['e'] = 0;
        found['i'] = 0;
        found['o'] = 0;
        found['u'] = 0;

        unordered_map<char, bool> vowels;
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;

        long long cnt_consonant = 0;

        long long ans = 0;

        while (r < n) {

            char ch = word[r];

            if (vowels[ch]) {
                found[ch]++;
            } else {
                cnt_consonant++;
            }

            while (found['a'] > 0 && found['e'] > 0 && found['i'] > 0 &&
                   found['o'] > 0 && found['u'] > 0 && cnt_consonant >= k) {
                ans += n - r;

                char ch_l = word[l];

                if (vowels[ch_l]) {
                    found[ch_l]--;
                } else {
                    cnt_consonant--;
                }
                l++;
            }

            r++;
        }

        return ans;
    }
};