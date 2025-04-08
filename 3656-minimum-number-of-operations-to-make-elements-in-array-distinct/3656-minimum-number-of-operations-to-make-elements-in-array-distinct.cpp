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
            if (freq[i].size() >= 2) {
                t = max(t, freq[i][freq[i].size() - 2]);
            }
        }

        if (t==-1){
            return 0;
        }

        t+=1;

        return ceil((double)t/3.0);
    }
};