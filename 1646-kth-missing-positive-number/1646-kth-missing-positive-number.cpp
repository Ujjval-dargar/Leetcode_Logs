class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<bool> t(1001, false);
        for (int i = 0; i < n; ++i) {
            t[arr[i]] = true;
        }

        for (int i = 1; i <= 1000; ++i) {
            if (!t[i])
                k--;
            if (k == 0)
                return i;
        }
        return 1000+k;
    }
};