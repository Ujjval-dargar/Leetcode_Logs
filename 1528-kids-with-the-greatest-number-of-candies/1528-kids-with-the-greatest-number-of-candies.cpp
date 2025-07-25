class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());

        int n = candies.size();
        vector<bool> ans(n, false);

        for (int i = 0; i < n; ++i) {
            ans[i] = (candies[i] + extraCandies) >= mx;
        }

        return ans;
    }
};