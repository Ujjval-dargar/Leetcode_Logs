class Solution {
public:
    unordered_map<string, int> mp;

    bool wordBreak(string s, vector<string>& wordDict) {
        for (string s : wordDict) {
            mp[s] = true;
        }

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            
            for (int j = 0; j < i; ++j) {

                if (dp[j] && mp[s.substr(j, i - j)]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};