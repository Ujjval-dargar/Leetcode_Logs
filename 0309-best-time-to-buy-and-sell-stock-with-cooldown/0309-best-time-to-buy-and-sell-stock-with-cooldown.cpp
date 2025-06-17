class Solution {
public:
    // int f(vector<int>& arr, int i, int buy, vector<vector<int>>& mem) {
    //     int n = arr.size();

    //     if (i >= n)
    //         return 0;

    //     if (mem[i][buy] != -1)
    //         return mem[i][buy];

    //     if (buy == 0) {
    //         return mem[i][buy] = max(f(arr, i + 1, 0, mem),
    //                                  -arr[i] + f(arr, i + 1, 1, mem));
    //     }

    //     if (buy == 1) {
    //         return mem[i][buy] = max(f(arr, i + 1, 1, mem),
    //                                  arr[i] + f(arr, i + 2, 0, mem));
    //     }

    //     return 0;
    // }

    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> mem(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 1; buy >= 0; --buy) {
                if (buy == 0) {
                    mem[i][buy] = max(mem[i + 1][0], -arr[i] + mem[i + 1][1]);
                }

                if (buy == 1) {
                    mem[i][buy] = max(mem[i + 1][1], arr[i] + mem[i + 2][0]);
                }
            }
        }

        return mem[0][0];
    }
};