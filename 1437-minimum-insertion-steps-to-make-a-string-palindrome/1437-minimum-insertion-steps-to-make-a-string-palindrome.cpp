class Solution {
public:
    // int f(string& s, int i, int j, vector<vector<int>>& mem) {

    //     if (i >= j) {
    //         return 0;
    //     }

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     if (s[i] == s[j]) {
    //         return mem[i][j] = f(s, i + 1, j - 1, mem);
    //     } else {
    //         return mem[i][j] =
    //                    1 + min(f(s, i + 1, j, mem), f(s, i, j - 1, mem));
    //     }
    // }

    int minInsertions(string s) {

        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i >= j) {
                    mem[i][j] = 0;
                    continue;
                }

                if (s[i] == s[j]) {
                    mem[i][j] = mem[i + 1][j - 1];
                } else {
                    mem[i][j] = 1 + min(mem[i + 1][j], mem[i][j - 1]);
                }
            }
        }

        return mem[0][n - 1];
    }
};