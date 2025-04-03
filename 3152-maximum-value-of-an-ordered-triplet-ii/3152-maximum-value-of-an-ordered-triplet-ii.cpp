class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n);
        vector<int> suffMax(n);

        preMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(nums[i], preMax[i - 1]);
        }

        suffMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMax[i] = max(suffMax[i + 1], nums[i]);
        }

        long long ans = 0;
        for (int j = 1; j < n - 1; ++j) {
            ans = max(ans, (long long)(preMax[j - 1] - nums[j]) * suffMax[j + 1]);
        }

        return ans;
    }
};