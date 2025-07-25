class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));

        long curr = INT_MIN;
        long mx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            curr = max((long)nums[i], curr + nums[i]);
            mx = max(curr, mx);
        }

        return mx;
    }
};