class Solution {
public:
    bool f(vector<int>& arr, int k, int i, int curr, vector<vector<int>>& mem) {
        if (curr == k)
            return true;

        int n = arr.size();
        if (i == n || curr > k)
            return false;

        if (mem[i][curr] != -1)
            return mem[i][curr];

        if (f(arr, k, i + 1, curr + arr[i], mem))
            return mem[i][curr] = true;
        if (f(arr, k, i + 1, curr, mem))
            return mem[i][curr] = true;

        return mem[i][curr] = false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2)
            return false;

        vector<vector<int>> mem(n, vector<int>(sum / 2, -1));
        return f(nums, sum / 2, 0, 0, mem);
    }
};