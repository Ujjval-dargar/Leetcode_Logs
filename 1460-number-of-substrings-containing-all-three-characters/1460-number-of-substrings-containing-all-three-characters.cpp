class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        mp['a'] = -1;
        mp['b'] = -1;
        mp['c'] = -1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            mp[s[i]] = i;

            ans += 1 + min(mp['a'], min(mp['b'], mp['c']));
        }

        return ans;
    }
};