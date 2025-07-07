class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    int time = 1;
    vector<vector<int>> dirn = {{0, 1}, {1, 0}};

    long long f(int i, int j, vector<vector<int>>& wait, vector<vector<long long>> &mem) {

        int m = wait.size();
        int n = wait[0].size();

        if (i == m - 1 && j == n - 1) {
            return 0;
        }

        if (mem[i][j]!=-1) return mem[i][j];

        long long cost = LLONG_MAX;

        if (time % 2) {
            for (int k = 0; k < 2; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (isValid(ni, nj, m, n)) {
                    time++;
                    cost = min(cost, (ni + 1) * (nj + 1) * 1LL + f(ni, nj, wait, mem));
                    time--;
                }
            }
        } else {
            time++;
            cost = wait[i][j] + f(i, j, wait, mem);
            time--;
        }

        return mem[i][j] = cost;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        vector<vector<long long>> mem(m,vector<long long>(n,-1)); 
        return 1 + f(0, 0, waitCost, mem);
    }
};