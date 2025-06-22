class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        vector<string> ans;
        string curr;

        for (int i = 0; i < n; ++i) {
            int t = curr.size();
            if (t == k) {
                ans.push_back(curr);
                curr = "";
            }
            curr += s[i];
        }

        if (curr != "") {
            int t = curr.size();
            for (int i = t + 1; i <= k; ++i) {
                curr += fill;
            }
            ans.push_back(curr);
        }

        return ans;
    }
};