class Solution {
public:
    int f(vector<int>& arr, int k, int i, int curr, vector<vector<int>>& mem,
          int& sum) {

        int n = arr.size();
        if (i == n) {
            if (curr == k)
                return 1;
            return 0;
        }

        if (mem[i][curr + sum] != -1)
            return mem[i][curr + sum];

        return mem[i][curr + sum] = f(arr, k, i + 1, curr - arr[i], mem, sum) +
                                    f(arr, k, i + 1, curr + arr[i], mem, sum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> mem(n, vector<int>(2 * sum + 1, -1));
        return f(nums, target, 0, 0, mem, sum);
    }
};