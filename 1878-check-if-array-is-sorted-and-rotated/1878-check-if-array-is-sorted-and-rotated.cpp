class Solution {
public:
    bool check(vector<int>& arr) {
        int t = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                t++;
        }

        if (t == 0)
            return true;
        if (t == 1 && arr[n - 1] <= arr[0])
            return true;

        return false;
    }
};