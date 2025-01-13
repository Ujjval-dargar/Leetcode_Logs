class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int ans = n;

        vector<int> arr(26, 0);
        for (int i = 0; i < n; ++i) {
            arr[s[i] - 'a']++;
        }

        for (int i = 0; i < n; ++i) {
            while (arr[s[i] - 'a'] > 2) {
                arr[s[i] - 'a'] -= 2;
                ans -= 2;
            }
        }

        return ans;
    }
};