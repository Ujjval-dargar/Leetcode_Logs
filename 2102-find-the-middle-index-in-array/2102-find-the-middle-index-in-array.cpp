class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> prefix(n);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] = sum;
        }

        for (int i = 0; i < n; ++i) {
            int left = prefix[i] - nums[i];
            int right = sum - prefix[i];
            if (left == right)
                return i;
        }

        return -1;
    }
};