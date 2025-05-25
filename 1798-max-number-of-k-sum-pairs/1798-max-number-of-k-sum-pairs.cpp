
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (mp[k - nums[i]] > 0) {
                x++;
                mp[k - nums[i]]--;
            } else {
                mp[nums[i]]++;
            }
        }

        return x;
    }
};