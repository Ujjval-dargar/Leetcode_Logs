class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int, pair<int, int>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for (int i = 0; i < n * m; ++i) {
            int r = mp[arr[i]].first;
            int c = mp[arr[i]].second;

            rows[r]++;
            cols[c]++;

            if (rows[r] == n || cols[c] == m) {
                return i;
            }
        }

        return -1;
    }
};