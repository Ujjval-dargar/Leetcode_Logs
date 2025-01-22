class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (arr[i][0] + arr[j][0] == target)
                return {arr[i][1], arr[j][1]};
            else if (arr[i][0] + arr[j][0] < target)
                i++;
            else
                j--;
        }

        return {};
    }
};