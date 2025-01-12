class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt == 0) {
                ans = nums[i];
            }

            if (ans != nums[i]) {
                cnt--;
            }else {
                cnt++;
            }
        }
        return ans;
    }
};