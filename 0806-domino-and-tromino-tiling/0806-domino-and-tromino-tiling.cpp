class Solution {
public:
    const int mod = 1000000007;
    vector<vector<long long>> matrix_mul(vector<vector<long long>>& fir,
                                         vector<vector<long long>>& sec) {
        long long n = fir.size(), m = sec[0].size(), k = sec.size();
        vector<vector<long long>> ans(n, vector<long long>(m));
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                ans[i][j] = 0;
                for (long long l = 0; l < k; l++) {
                    ans[i][j] =
                        (ans[i][j] + (fir[i][l] * sec[l][j]) % mod) % mod;
                }
            }
        }
        return ans;
    }

    int numTilings(int n) {
        vector<vector<long long>> cnst = {
            {1, 0, 1, 1}, 
            {2, 1, 0, 0}, 
            {1, 0, 0, 0}, 
            {0, 1, 0, 0}
        };

        vector<vector<long long>> ans(4, vector<long long>(4));
        for (long long i = 0; i < 4; i++)
            ans[i][i] = 1;
        
        while (n) {
            if (n % 2) {
                ans = matrix_mul(ans, cnst);
            }
            cnst = matrix_mul(cnst, cnst);
            n /= 2;
        }

        return ans[0][0];
    }
};