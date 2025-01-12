class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int m = arr[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            ans = max(ans, m - arr[i]);
            m = max(m, arr[i]);
        }
        return ans;
    }
};