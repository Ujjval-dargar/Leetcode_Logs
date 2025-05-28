class Solution {
public:
    void f(vector<string> &ans, int n, string curr, int cnt1, int cnt2) {
        if (cnt1 == n && cnt2 == n) {
            ans.push_back(curr);
            return;
        }

        if (cnt1 < n) {
            f(ans, n, curr + "(", cnt1 + 1, cnt2);
        }

        if (cnt2 < n && cnt1 > cnt2) {
            f(ans, n, curr + ")", cnt1, cnt2 + 1);
        }
    }

    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        f(ans,n,"",0,0);
        return ans;
    }
};