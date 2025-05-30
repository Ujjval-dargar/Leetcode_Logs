class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int row = m - 1;
        int col = 0;
        int ans = 0;
        while (row >= 0 && col < n) {
            // cout<<row<<"-"<<col<<" "<<grid[row][col]<<" "<<ans<<"-";
            if (grid[row][col] < 0) {
                ans += n - col;
                row--;
            } else {
                col++;
            }
            cout<<ans<<endl;
        }

        return ans;
    }
};