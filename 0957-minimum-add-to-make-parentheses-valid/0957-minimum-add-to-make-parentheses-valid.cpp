class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int n = s.size();

        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '(')
                stk.push(ch);
            else {
                if (stk.empty()) {
                    ans++;
                } else {
                    stk.pop();
                }
            }
        }

        return ans + stk.size();
    }
};