class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    vector<vector<int>> dirn = {{0, 1}, {1, 0}};

    // long long f(int i, int j, int time, vector<vector<int>>& wait,
    //             vector<vector<vector<long long>>>& mem) {

    //     int m = wait.size();
    //     int n = wait[0].size();

    //     if (i == m - 1 && j == n - 1) {
    //         return 0;
    //     }

    //     if (mem[i][j][time] != -1)
    //         return mem[i][j][time];

    //     long long cost = LLONG_MAX;

    //     if (time) {
    //         for (int k = 0; k < 2; ++k) {
    //             int ni = i + dirn[k][0];
    //             int nj = j + dirn[k][1];

    //             if (isValid(ni, nj, m, n)) {
    //                 cost = min(cost, (ni + 1) * (nj + 1) * 1LL +
    //                                      f(ni, nj, !time, wait, mem));
    //             }
    //         }
    //     } else {
    //         cost = wait[i][j] + f(i, j, !time, wait, mem);
    //     }

    //     return mem[i][j][time] = cost;
    // }

    // long long minCost(int m, int n, vector<vector<int>>& waitCost) {

    //     vector<vector<vector<long long>>> mem(
    //         m, vector<vector<long long>>(n, vector<long long>(2, -1)));
    //     return 1 + f(0, 0, 1, waitCost, mem);
    // }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        vector<vector<vector<long long>>> mem(
            m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                for (int time = 1; time >= 0; --time) {

                    if (i == m - 1 && j == n - 1) {
                        mem[i][j][time] = 0LL;
                        continue;
                    }

                    long long cost = LLONG_MAX;

                    if (time) {
                        for (int k = 0; k < 2; ++k) {
                            int ni = i + dirn[k][0];
                            int nj = j + dirn[k][1];

                            if (isValid(ni, nj, m, n)) {
                                cost =
                                    min(cost, (ni + 1) * (nj + 1) * 1LL +
                                                  mem[ni][nj][!time]);
                            }
                        }
                    } else {
                        cost = waitCost[i][j] + mem[i][j][!time];
                    }

                    mem[i][j][time] = cost;
                }
            }
        }

        return 1 + mem[0][0][1];
    }
};