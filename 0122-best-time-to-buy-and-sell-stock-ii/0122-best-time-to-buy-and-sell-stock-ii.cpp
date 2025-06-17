class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> mem(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {

            mem[i][0] = max(mem[i + 1][0], -arr[i] + mem[i + 1][1]);
            mem[i][1] = max(mem[i + 1][1], arr[i] + mem[i + 1][0]);
        }

        return mem[0][0];
    }
};