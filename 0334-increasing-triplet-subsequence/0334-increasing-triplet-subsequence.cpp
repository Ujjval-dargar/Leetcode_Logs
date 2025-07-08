class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int> right(n, INT_MIN);
        vector<int> left(n, INT_MAX);

        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i - 1], nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], nums[i + 1]);
        }

        for (int i = 0; i < n; ++i){
            if (left[i] < nums[i] && nums[i] < right[i]) return true;
        }

        return false;
    }
};