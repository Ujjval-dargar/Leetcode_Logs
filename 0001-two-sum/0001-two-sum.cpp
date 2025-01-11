class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        int l = 0;
        int r = n - 1;
        while (l < r) {
            int t = temp[l].first + temp[r].first;
            if (t == target) {
                return {temp[l].second, temp[r].second};
            } else if (t > target) {
                r--;
            } else {
                l++;
            }
        }

        return {};
    }
};