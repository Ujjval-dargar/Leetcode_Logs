class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans=0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it = lower_bound(nums.begin()+j+1,nums.end(),nums[i]+nums[j]);
                ans+=it-nums.begin()-1-j;
            }
        }
        return ans;
    }
};