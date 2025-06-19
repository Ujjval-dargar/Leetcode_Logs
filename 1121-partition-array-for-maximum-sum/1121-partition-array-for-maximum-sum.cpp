class Solution {
public:
    // int f(vector<int>& arr, int k, int i, vector<int>& mem) {
    //     int n = arr.size();

    //     if (i == n)
    //         return 0;

    //     if (mem[i] != -1)
    //         return mem[i];

    //     int mx = INT_MIN;
    //     for (int len = 1; len <= k && i + len <= n; ++len) {
    //         int currPart =
    //             len * (*max_element(arr.begin() + i, arr.begin() + i + len)) +
    //             f(arr, k, i + len, mem);
    //         mx = max(mx, currPart);
    //     }

    //     return mem[i] = mx;
    // }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> mem(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int mx = INT_MIN;
            for (int len = 1; len <= k && i + len <= n; ++len) {
                int currPart = len * (*max_element(arr.begin() + i,
                                                   arr.begin() + i + len)) +
                               mem[i + len];
                mx = max(mx, currPart);
            }

            mem[i] = mx;
        }
        return mem[0];
    }
};