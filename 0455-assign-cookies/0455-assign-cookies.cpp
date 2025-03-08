class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int>> greed(g.begin(), g.end());
        priority_queue<int, vector<int>, greater<int>> sze(s.begin(), s.end());

        int ans = 0;
        while (!greed.empty() && !sze.empty()){
            int a = greed.top();
            int b = sze.top();

            if (b<a){
                sze.pop();
            }else {
                ans++;
                greed.pop();
                sze.pop();
            }
        }

        return ans;
    }
};