class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> stk;

        for (int i = 0; i < n; ++i) {
            if (stk.empty() || stk.top().first != s[i]) {
                stk.push({s[i], 1});
            } else {
                pair<char, int> p = stk.top();
                stk.pop();
                char ch = p.first;
                int cnt = p.second + 1;

                if (cnt >= k) {
                    cnt -= k;
                }

                if (cnt > 0)
                    stk.push({ch, cnt});
            }
        }

        string ans;
        while (!stk.empty()) {
            pair<char, int> p = stk.top();
            stk.pop();

            char ch = p.first;
            int cnt = p.second;

            string temp;
            for (int i = 0; i < cnt; ++i) {
                temp += ch;
            }

            ans += temp;
        }

        return string(ans.rbegin(), ans.rend());
    }
};