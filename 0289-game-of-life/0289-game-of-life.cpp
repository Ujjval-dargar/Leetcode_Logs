class Solution {
public:
    int count1(vector<vector<int>>& board, int i, int j, int m, int n) {
        int cnt = 0;
        vector<vector<int>> dirn = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        for (vector<int>& dir : dirn) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n && board[ni][nj] == 1)
                cnt++;
        }

        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> org = board;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = count1(org, i, j, m, n);

                if (org[i][j] == 1) {
                    if (cnt < 2) board[i][j] = 0;
                    if (cnt == 2 || cnt == 3) board[i][j] = 1;
                    if (cnt > 3) board[i][j] = 0;
                
                } else if (org[i][j] == 0) {
                    if (cnt == 3) board[i][j] = 1;
                }
            }
        }
    }
};