class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        if (n < 4)
            return {};

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {

            if (nums[i]>target) continue;

            while (i - 1 >= 0 && i < n && nums[i - 1] == nums[i]) {
                i++;
            }

            for (int j = i + 1; j < n; ++j) {
                
                if (nums[i]+nums[j]>target) continue;
                

                while (j > i + 1 && j < n && nums[j - 1] == nums[j]) {
                    j++;
                }

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long s = nums[i] + nums[j] + nums[k] + nums[l];

                    if (s == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while (k < n && nums[k - 1] == nums[k])
                            k++;
                    } 
                    else if (s < target)
                        k++;
                    else
                        l--;
                }
            }
        }

        return ans;
    }
};