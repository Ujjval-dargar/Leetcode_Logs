class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> dirn = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            vector<int> f = q.front();
            q.pop();

            int i = f[0];
            int j = f[1];

            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (isValid(ni, nj, m, n) && !visited[ni][nj] &&
                    mat[ni][nj] != 0) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                    mat[ni][nj] = 1 + mat[i][j];
                }
            }
        }

        return mat;
    }
};