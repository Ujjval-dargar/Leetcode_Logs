class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }

    // int f(string& s, int i, vector<int>& mem) {
    //     int n = s.size();

    //     if (i == n)
    //         return 0;

    //     if (mem[i] != -1)
    //         return mem[i];

    //     int mn = INT_MAX;
    //     for (int j = i; j < n; ++j) {
    //         if (isPal(s, i, j)) {
    //             mn = min(mn, 1 + f(s, j + 1, mem));
    //         }
    //     }

    //     return mem[i] = mn;
    // }

    int minCut(string s) {
        int n = s.size();

        vector<int> mem(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int mn = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPal(s, i, j)) {
                    mn = min(mn, 1 + mem[j + 1]);
                }
            }
            mem[i] = mn;
        }

        return mem[0] - 1;
    }
};