class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> arr(n * n + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[grid[i][j]]++;
            }
        }

        int a = -1;
        int b = -1;
        for (int i = 1; i <= n * n; ++i) {
            if (arr[i] == 2)
                a = i;
            if (arr[i] == 0)
                b = i;
        }

        return {a, b};
    }
};