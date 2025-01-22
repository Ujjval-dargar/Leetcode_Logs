class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();

        int t1 = 1;
        int t2 = 1;

        for (int i = 0; i < n; ++i) {
            t1 *= nums[i];
            t2 *= nums[n - i - 1];

            ans = max({t1, t2, ans});

            if (t1 == 0)
                t1 = 1;
            if (t2 == 0)
                t2 = 1;
        }

        return ans;
    }
};