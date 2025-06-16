class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<>> greed(g.begin(), g.end());
        priority_queue<int, vector<int>, greater<>> sz(s.begin(), s.end());

        int ans = 0;
        while (!greed.empty() && !sz.empty()) {
            if (sz.top() < greed.top()) {
                sz.pop();
            } else {
                ans++;
                sz.pop();
                greed.pop();
            }
        }

        return ans;
    }
};