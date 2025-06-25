class Solution {

private:
    vector<string> ans;

    string helper(string s) {
        string ans;

        int n = s.size();
        for (int i = 0; i < n;) {
            int cnt = 0;
            char ch = s[i];
            while (s[i] == ch) {
                cnt++;
                i++;
            }

            ans += ('0' + cnt);
            ans += ch;
        }

        return ans;
    }

public:
    Solution() {
        ans.resize(31);
        ans[1] = "1";
        for (int i = 2; i <= 30; ++i) {
            ans[i] = helper(ans[i - 1]);
        }
    }

    string countAndSay(int n) { return ans[n]; }
};