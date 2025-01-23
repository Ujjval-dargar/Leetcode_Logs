class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        intervals.push_back({INT_MAX,INT_MAX});
        int n = intervals.size();

        vector<vector<int>> ans;

        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            int nl = intervals[i][0];
            int nr = intervals[i][1];

            if (nl <= r && nr > r) {
                r = nr;
            } else if (nl > r) {
                ans.push_back({l, r});
                l = nl;
                r = nr;
            }
        }

        return ans;
    }
};