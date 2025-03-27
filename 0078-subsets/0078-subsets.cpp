
class Solution {
public:
    vector<int> fetch(int a, vector<int>& nums) {

        vector<int> ans;
        for (int i = 0; i <= 12; ++i) {
            if (((a >> i) & 1) == 1) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int s = (1 << n);

        vector<vector<int>> ans;
        for (int i = 0; i < s; ++i) {
            ans.push_back(fetch(i, nums));
        }

        return ans;
    }
};