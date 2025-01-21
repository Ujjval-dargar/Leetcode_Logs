class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int m = 2;
        int n = grid[0].size();

        long long s1 = 0;
        long long s2 = 0;

        for (int i = 0; i < n; ++i) {
            s1 += grid[0][i];
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            s1 -= grid[0][i];
            ans = min(ans, max(s1, s2));
            s2 += grid[1][i];
        }

        return ans;
    }
};