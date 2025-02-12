class Solution {
public:
    int digitSum(int num) {
        int s = 0;
        while (num > 0) {
            s += num % 10;
            num = num / 10;
        }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            mp[digitSum(nums[i])].push_back(nums[i]);
        }

        int ans = -1;
        for (auto i : mp) {
            int m = i.second.size();
            if (m >= 2) {
                ans = max(i.second[m - 1] + i.second[m - 2], ans);
            }
        }

        return ans;
    }
};