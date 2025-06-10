class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int ans = 0;
        stack<int> s;

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || arr[s.top()] >= arr[i])) {
                int mid = s.top();
                s.pop();
                int l = s.empty() ? -1 : s.top();

                long long contri = 1LL * (i - mid) * (mid - l) * arr[mid];
                ans = (ans + contri) % mod;
            }
            s.push(i);
        }

        return ans;
    }
};