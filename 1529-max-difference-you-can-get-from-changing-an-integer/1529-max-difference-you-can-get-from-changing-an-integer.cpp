class Solution {
public:
    string f(string& s, char x, char y) {
        string ans = s;
        int n = ans.size();
        for (int i = 0; i < n; ++i) {
            if (ans[i] == x)
                ans[i] = y;
        }

        return ans;
    }

    int maxDiff(int num) {
        string nm = to_string(num);
        int n = nm.size();

        int mn = num;
        int mx = num;

        for (char x = '0'; x <= '9'; ++x) {
            for (char y = '0'; y <= '9'; ++y) {
                string s = f(nm, x, y);
                int t = stoi(s);
                if (t != 0 && s[0] != '0') {
                    mn = min(mn, t);
                    mx = max(mx, t);
                }
            }
        }

        return mx - mn;
    }
};