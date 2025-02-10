class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};