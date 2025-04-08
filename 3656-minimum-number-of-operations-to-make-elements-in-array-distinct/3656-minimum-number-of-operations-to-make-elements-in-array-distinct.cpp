class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> freq(101, vector<int>());

        for (int i = 0; i < n; ++i) {
            freq[nums[i]].push_back(i);
        }

        int t = -1;
        for (int i = 1; i <= 100; ++i) {
            int m = freq[i].size();
            if (m >= 2) {
                t = max(t, freq[i][m - 2]);
            }
        }

        if (t==-1){
            return 0;
        }

        t+=1;

        return ceil((double)t/3.0);
    }
};