class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        string temp = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (temp != "") {
                    ans = temp + " " + ans;
                    temp = "";
                }
            } else {
                temp.push_back(s[i]);
            }
        }

        if (temp != "") {
            ans = temp + " " + ans;
        }

        ans.pop_back();

        return ans;
    }
};