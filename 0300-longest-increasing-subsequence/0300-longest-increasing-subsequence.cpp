class Solution {
public:
    // int f(vector<int>& arr, int i, int prev, vector<vector<int>>& mem) {
    //     int n = arr.size();
    //     if (i == n)
    //         return 0;

    //     if (mem[i][prev] != -1)
    //         return mem[i][prev];

    //     int notTake = f(arr, i + 1, prev, mem);
    //     int take = 0;
    //     if (prev == n || arr[prev] < arr[i]) {
    //         take = 1 + f(arr, i + 1, i, mem);
    //     }

    //     return mem[i][prev] = max(take, notTake);
    // }

    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int prev = n; prev >= 0; --prev) {
                int notTake = mem[i + 1][prev];
                int take = 0;
                if (prev == n || arr[prev] < arr[i]) {
                    take = 1 + mem[i + 1][i];
                }

                mem[i][prev] = max(take, notTake);
            }
        }
        return mem[0][n];
    }
};