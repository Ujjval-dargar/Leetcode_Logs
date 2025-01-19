class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int mx = height[0];
        for (int i = 1; i < n; ++i) {
            left[i] = mx;
            mx = max(height[i], mx);
        }

        mx = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = mx;
            mx = max(height[i], mx);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += max(0, min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};