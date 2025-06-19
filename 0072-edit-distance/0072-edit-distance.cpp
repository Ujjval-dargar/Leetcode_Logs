class Solution {
public:
    // int f(string& s1, string& s2, int i, int j, vector<vector<int>>& mem) {
    //     int n1 = s1.size();
    //     int n2 = s2.size();
    //     if (j == n2)
    //         return n1 - i;
    //     if (i == n1)
    //         return n2 - j;

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     int insrt = INT_MAX;
    //     int dlt = INT_MAX;
    //     int rplc = INT_MAX;
    //     int nothing = INT_MAX;

    //     dlt = 1 + f(s1, s2, i + 1, j, mem);
    //     insrt = 1 + f(s1, s2, i, j + 1, mem);

    //     if (s1[i] == s2[j])
    //         nothing = f(s1, s2, i + 1, j + 1, mem);
    //     else
    //         rplc = 1 + f(s1, s2, i + 1, j + 1, mem);

    //     return mem[i][j] = min({rplc, dlt, insrt, nothing});
    // }

    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1; i >= 0; --i) {
            for (int j = n2; j >= 0; --j) {
                if (j == n2){ mem[i][j] = n1 - i; continue; }
                if (i == n1){ mem[i][j] = n2 - j; continue; }

                int insrt = INT_MAX;
                int dlt = INT_MAX;
                int rplc = INT_MAX;
                int nothing = INT_MAX;

                dlt = 1 + mem[i + 1][j];
                insrt = 1 + mem[i][j + 1];

                if (s1[i] == s2[j])
                    nothing = mem[i + 1][j + 1];
                else
                    rplc = 1 + mem[i + 1][j + 1];

                mem[i][j] = min({rplc, dlt, insrt, nothing});
            }
        }
        return mem[0][0];
    }
};