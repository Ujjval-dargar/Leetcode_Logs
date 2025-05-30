class Solution {
public:
    int bs(vector<pair<int, int>> arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (arr[mid].first >= k) {
                ans = arr[mid].second;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> strt;
        for (int i = 0; i < n; ++i) {
            strt.push_back({intervals[i][0], i});
        }

        sort(strt.begin(), strt.end());
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(bs(strt, intervals[i][1]));
        }

        return ans;
    }
};