
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {

            int e1 = nums[i];

            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int e2 = nums[j];
                int e3 = nums[k];

                int s = e1 + e2 + e3;
                if (s == 0) {
                    ans.push_back({e1, e2, e3});
                    
                    while (j<n && nums[j]==e2) j++;
                    
                } else if (s > 0)
                    k--;
                else
                    j++;
            }
        }

        return ans;
    }
};