class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < n; ++i) {

            char ch = s[i];
            if (ch == ')')
                c2++;
            if (c1 != c2) {
                ans.push_back(ch);
            }
            if (ch == '(')
                c1++;
            
        }

        return ans;
    }
};