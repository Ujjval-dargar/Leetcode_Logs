class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                int mxf = INT_MIN, mnf = INT_MAX;
                int mx = -1, mn = -1;

                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > mxf) {
                        mxf = freq[k];
                        mx = k;
                    }
                    if (freq[k] < mnf &&
                        freq[k] > 0) { 
                        mnf = freq[k];
                        mn = k;
                    }
                }
                ans += mxf-mnf;
            }
        }

        return ans;
    }
};