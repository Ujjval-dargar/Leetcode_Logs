class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int l = arr[0][0];
        int r = arr[0][1];

        vector<vector<int>> ans;

        for (int i = 1; i < n; ++i) {
            int tl = arr[i][0];
            int tr = arr[i][1];

            if (tl <= r && tr > r) {
                r = tr;

            } else if (tl > r) {
                ans.push_back({l, r});
                l = tl;
                r = tr;
            }
        }
        ans.push_back({l, r});

        return ans;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> merged = mergeInterval(meetings);
        int n = merged.size();

        int d = 0;

        for (int i = 0; i < n; ++i) {
            d += merged[i][1] - merged[i][0] + 1;
        }

        return days - d;
    }
};