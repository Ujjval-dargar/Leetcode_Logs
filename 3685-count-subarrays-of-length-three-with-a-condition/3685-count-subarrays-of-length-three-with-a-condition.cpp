class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0;
        int j = 2;
        int n = nums.size();
        int ans = 0;
        while (j < n) {
            
            if (nums[i] + nums[j] == 0.5 * nums[(i + j) / 2]) {
                ans++;
            }
            i++;
            j++;
        }
        return ans;
    }
};