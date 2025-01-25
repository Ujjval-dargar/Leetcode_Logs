class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> ans;

        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, queue<int>> group;
        unordered_map<int, int> mp;

        group[0].push(sorted[0]);
        mp[sorted[0]] = 0;

        int grp = 0;
        for (int i = 1; i < n; ++i) {
            if (sorted[i] - sorted[i - 1] > limit) {
                grp++;
            }
            group[grp].push(sorted[i]);
            mp[sorted[i]] = grp;
        }

        for (int i = 0; i < n; ++i) {
            int t = group[mp[nums[i]]].front();
            group[mp[nums[i]]].pop();
            ans.push_back(t);
        }

        return ans;
    }
};