class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int ans = 0;

        unordered_map<int, int> mp;
        int cnt = 0;

        while (r < n) {
            mp[nums[r]]++;
            if (mp[nums[r]] == 1) {
                cnt++;
            }

            while (l <= r && cnt > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    cnt--;
                }
                l++;
            }

            ans += r - l + 1;
            r++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};