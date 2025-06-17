class Solution {
public:
    // int f(string& s1, string& s2, int i, int j, vector<vector<int>>& mem) {
    //     int n1 = s1.size();
    //     int n2 = s2.size();

    //     if (i == n1 || j == n2)
    //         return (max(n1 - i, n2 - j));

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     if (s1[i] == s2[j]) {
    //         return mem[i][j] = f(s1, s2, i + 1, j + 1, mem);
    //     }

    //     return mem[i][j] =
    //                1 + min(f(s1, s2, i + 1, j, mem), f(s1, s2, i, j + 1, mem));
    // }

    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1, 0));
        for (int j = 0; j <= n2; ++j) {
            mem[n1][j] = n2 - j;
        }

        for (int i = 0; i <= n1; ++i) {
            mem[i][n2] = n1 - i;
        }

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    mem[i][j] = mem[i + 1][j + 1];
                } else {
                    mem[i][j] = 1 + min(mem[i + 1][j], mem[i][j + 1]);
                }
            }
        }

        return mem[0][0];
    }
};