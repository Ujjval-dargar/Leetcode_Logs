class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            mp.insert(nums[i]);
        }

        for (auto i : mp) {
            if (mp.find(i-1) == mp.end()) {
                int ele = i+1;
                int cnt = 1;
                while (mp.find(ele)!=mp.end()){
                    ele++;
                    cnt++;
                }
                ans = max(cnt, ans);
            }
        }

        return ans;
    }
};