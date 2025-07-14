class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        stack<int> s;
        int ans = 0;
        for (int i = 0; i <= n; ++i){
            while (!s.empty() && (i == n || arr[s.top()] >= arr[i]))
            {
                int mid = s.top();
                s.pop();

                int left = (s.empty())? -1 : s.top();
                int right  = i;

                int cont = (1LL * (mid - left) * (right - mid) * arr[mid]) % mod;
                ans = (ans + cont) % mod;
            }
            s.push(i);
        }

        return ans;
    }
};