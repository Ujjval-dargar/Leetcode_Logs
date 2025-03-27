
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        string ans = "";
        int j = 0;
        int s = strs[0].size();

        for (int i = 1; i < n; ++i) {
            s = min(s, (int)strs[i].size());
        }

        while (j < s) {
            char ch = strs[0][j];
            for (int i = 1; i < n; ++i) {
                if (ch != strs[i][j]) {
                    return ans;
                }
            }
            ans.push_back(ch);
            j++;
        }

        return ans;
    }
};