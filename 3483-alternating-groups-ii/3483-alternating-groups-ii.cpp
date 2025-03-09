class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k-1; ++i) {
            colors.push_back(colors[i]);
        }

        int n = colors.size();
        int l = 0;
        int r = 1;
        int ans = 0;

        while (r < n) {
            if (colors[r - 1] == colors[r]) {
                l = r;
            }

            if (r - l + 1 == k) {
                ans++;
                l++;
            }

            r++;
        }

        return ans;
    }
};