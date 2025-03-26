class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr.push_back(grid[i][j]);
            }
        }

        int s = arr.size();
        for (int i = 1; i < s; ++i) {
            if (arr[i - 1] % x != arr[i] % x) {
                return -1;
            }
        }

        sort(arr.begin(),arr.end());
        int ans = 0;
        int mdn = arr[s / 2];
        for (int i = 0; i < s; ++i) {
            ans += abs(arr[i] - mdn) / x;
        }

        return ans;
    }
};