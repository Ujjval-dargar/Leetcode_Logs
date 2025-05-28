class Solution {
public:
    void f(vector<int>& nums, int i, vector<vector<int>>& ans,
           vector<int> curr) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        f(nums, i + 1, ans, curr);
        curr.push_back(nums[i]);
        f(nums, i + 1, ans, curr);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        f(nums, 0, ans, {});
        return ans;
    }
};