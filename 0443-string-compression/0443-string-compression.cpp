class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> ans;

        for (int i = 0; i < n;) {
            int cnt = 0;
            int j = i;
            while (j < n && chars[i] == chars[j]) {
                cnt++;
                j++;
            }

            ans.push_back(chars[i]);
            i = j;

            if (cnt > 1) {
                string s = to_string(cnt);
                for (char ch : s) {
                    ans.push_back(ch);
                }
            }
        }

        chars = ans;

        return ans.size();
    }
};