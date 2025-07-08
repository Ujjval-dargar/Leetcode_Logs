// brute

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();

//         int mod = 1e9 + 7;
//         int ans = 0;
//         for (int i = 0; i < n; ++i){
//             for (int j = i; j < n; ++j){
//                 int len = j - i + 1;
//                 int mn = *min_element(arr.begin() + i, arr.begin() + i +
//                 len); ans = (ans + mn) % mod;
//             }
//         }

//         return ans;
//     }
// };

// -------------------------------------------------------------------------------------------------

// Optimal

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
                int left = s.empty() ? -1 : s.top();

                ans =
                    (ans + (1LL * (mid - left) * (i - mid) * arr[mid]) % mod) %
                    mod;
            }
            s.push(i);
        }

        return ans;
    }
};