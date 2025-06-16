class Solution {
public:
    // int f(string& s, int i, int j, vector<vector<int>>& mem) {
    //     if (i > j)
    //         return 0;

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     int take = 0;
    //     int notTake = 0;

    //     if (s[i] == s[j]) {
    //         take = 2 + f(s, i + 1, j - 1, mem);
    //     }

    //     notTake = max(f(s, i + 1, j, mem), f(s, i, j - 1, mem));
    //     return mem[i][j] = max(take, notTake);
    // }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> mem(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {

                if (i > j) {
                    mem[i][j] = 0;
                    continue;
                }

                if (i == j) {
                    mem[i][j] = 1;
                    continue;
                }

                int take = 0;
                int notTake = 0;

                if (s[i] == s[j]) {
                    take = 2 + mem[i + 1][j - 1];
                }

                notTake = max(mem[i + 1][j], mem[i][j - 1]);

                mem[i][j] = max(take, notTake);
            }
        }

        return mem[0][n - 1];
    }
};