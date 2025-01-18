class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;

        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j += 2) {
                    ans.push_back(grid[i][j]);
                }
            } else {
                int j;
                if (n % 2 == 0)
                    j = n - 1;
                else
                    j = n - 2;
                for (; j >= 0; j -= 2) {
                    ans.push_back(grid[i][j]);
                }
            }
        }
        return ans;
    }
};