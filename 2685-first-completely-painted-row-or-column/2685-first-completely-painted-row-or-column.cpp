class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        int t = n * m;

        for (int i = 0; i < t; ++i) {

            if (++rows[mp[arr[i]][0]] == n || ++cols[mp[arr[i]][1]] == m) 
                return i;
            
        }

        return -1;
    }
};