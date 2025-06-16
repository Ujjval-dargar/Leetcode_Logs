class Solution {
public:
    int f(vector<int>& coins, int amount, int i, long long curr,
          vector<vector<int>>& mem) {

        if (curr == amount)
            return 0;
        if (curr > amount)
            return INT_MAX;

        int n = coins.size();
        if (i == n)
            return INT_MAX;

        if (mem[i][curr] != -1)
            return mem[i][curr];

        return mem[i][curr] =
                   min(1LL + f(coins, amount, i, 0LL + curr + coins[i], mem),
                       (long long)f(coins, amount, i + 1, curr, mem));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> mem(n, vector<int>(amount + 1, -1));

        int ans = f(coins, amount, 0, 0, mem);
        return ans == INT_MAX ? -1 : ans;
    }
};