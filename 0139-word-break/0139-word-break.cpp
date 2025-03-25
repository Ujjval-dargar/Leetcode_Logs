class Solution {
public:
    unordered_map<string, bool> mp;

    bool helper(string s) {

        if (s=="") return true;

        if (mp.find(s) != mp.end()) return mp[s];

        int n = s.size();

        for (int i = 0; i < n; ++i) {
            string s1 = s.substr(0, i + 1);
            string s2 = s.substr(i+1);
            
            if (mp[s1]) {
                if (helper(s2)) {
                    return mp[s2] = true;
                }
            }
        }

        return mp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for (string t : wordDict) {
            mp[t] = true;
        }
        return helper(s);
    }
};