class Solution {
public:

    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> mem(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 1; buy >= 0; --buy) {
                for (int cnt = k - 1; cnt >= 0; --cnt) {
                    if (buy == 0) {
                        mem[i][buy][cnt] = max(mem[i + 1][0][cnt],
                                               -arr[i] + mem[i + 1][1][cnt]);
                    }

                    if (buy == 1) {
                        mem[i][buy][cnt] = max(mem[i + 1][1][cnt],
                                               arr[i] + mem[i + 1][0][cnt + 1]);
                    }
                }
            }
        }

        return mem[0][0][0];
    }
};