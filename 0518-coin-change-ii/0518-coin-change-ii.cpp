class Solution {
public:
    int f(vector<int>& coins, int k, int i, int curr,
          vector<vector<int>>& mem) {

        int n = coins.size();
        if (i == n) {
            if (curr == k)
                return 1;
            return 0;
        }

        if (curr > k)
            return 0;

        if (mem[i][curr] != -1)
            return mem[i][curr];

        return mem[i][curr] = f(coins, k, i, curr + coins[i], mem) +
                              f(coins, k, i + 1, curr, mem);
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> mem(n, vector<int>(amount + 1, -1));

        return f(coins, amount, 0, 0, mem);
    }
};