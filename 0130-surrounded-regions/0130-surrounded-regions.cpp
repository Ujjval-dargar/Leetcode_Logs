class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                visited[i][n - 1] = true;
            }
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                visited[0][j] = true;
            }
            if (board[m - 1][j] == 'O') {
                q.push({m - 1, j});
                visited[m - 1][j] = true;
            }
        }

        vector<vector<int>> dirn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            vector<int> f = q.front();
            q.pop();

            int i = f[0];
            int j = f[1];

            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (isValid(ni, nj, m, n) && board[ni][nj] == 'O' &&
                    !visited[ni][nj]) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};