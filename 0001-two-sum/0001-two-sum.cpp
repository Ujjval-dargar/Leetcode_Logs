class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            if (mp[target - nums[i]] > 0)
                return {i, mp[target - nums[i]] - 1};
            mp[nums[i]] = i + 1;
        }

        return {};
    }
};