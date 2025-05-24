class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            prefix[i] = sum;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int l = j - i + 1;
                if (l % 2) {
                    ans += (i - 1 < 0) ? prefix[j] : prefix[j] - prefix[i - 1];
                }
            }
        }

        return ans;
    }
};