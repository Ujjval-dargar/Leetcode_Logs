class Solution {
public:
    // bool f(string& s1, string& s2, int i, int j, vector<vector<int>>& mem) {

    //     int n1 = s1.size();
    //     int n2 = s2.size();

    //     if (i == n1)
    //         return true;

    //     if (j == n2)
    //         return false;

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     if (s1[i] == s2[j]) {
    //         return mem[i][j] = f(s1, s2, i + 1, j + 1, mem);
    //     } else {
    //         return mem[i][j] = f(s1, s2, i, j + 1, mem);
    //     }
    // }

    bool isSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<bool>> mem(n1 + 1, vector<bool>(n2 + 1, false));

        for (int i = n1; i >= 0; --i) {
            for (int j = n2; j >= 0; --j) {
                if (i == n1) {
                    mem[i][j] = true;
                    continue;
                }

                if (j == n2) {
                    mem[i][j] = false;
                    continue;
                }

                if (s1[i] == s2[j]) {
                    mem[i][j] = mem[i + 1][j + 1];
                } else {
                    mem[i][j] = mem[i][j + 1];
                }
            }
        }

        return mem[0][0];
    }
};