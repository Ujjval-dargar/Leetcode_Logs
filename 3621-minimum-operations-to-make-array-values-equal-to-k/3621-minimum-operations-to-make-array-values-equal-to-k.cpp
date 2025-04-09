class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int mn = INT_MAX;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
            mn = min(mn, nums[i]);
        }

        if (k > mn) {
            return -1;
        }

        int ans = mp.size();

        return (k == mn ? ans - 1 : ans);
    }
};