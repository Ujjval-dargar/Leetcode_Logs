class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for (char ch : num) {
            while (k > 0 && !s.empty() && s.top() > ch) {
                s.pop();
                k--;
            }

            s.push(ch);
        }

        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        if (s.empty())
            return "0";
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        while (ans[0] == '0') {
            ans = ans.substr(1);
        }

        if (ans == "")
            return "0";
        return ans;
    }
};