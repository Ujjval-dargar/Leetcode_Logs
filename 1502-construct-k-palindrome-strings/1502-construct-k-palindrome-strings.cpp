class Solution {
public:
    bool canConstruct(string s, int k) {

        int n=s.size();
        if (n == k)
            return true;
        if (n < k)
            return false;

        vector<int> freq(26, 0);

        for (int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
        }

        int oc = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2)
                oc++;
        }

        return oc <= k;
    }
};