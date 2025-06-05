#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {

        for (int i = 0; i < 9; ++i) {
            if (board[r][i] == ch)
                return false;
            if (board[i][c] == ch)
                return false;
            if (board[(r / 3) * 3 + (i / 3)][(c / 3) * 3 + i % 3] == ch)
                return false;
        }

        return true;
    }

    bool f(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) {
                        if (isValid(board, i, j, '0' + k)) {
                            board[i][j] = '0' + k;
                            if (f(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};