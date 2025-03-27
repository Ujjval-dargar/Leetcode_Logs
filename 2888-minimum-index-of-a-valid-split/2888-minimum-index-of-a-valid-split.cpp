class Solution {
public:
    int minimumIndex(vector<int>& arr) {

        int n = arr.size();
        vector<int> p1(n, -1);
        vector<int> p2(n, -1);

        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++;
            if (mp[arr[i]] > (i + 1) / 2) {
                p1[i] = arr[i];
            } else {
                int t = p1[i - 1];
                if (mp[t] > (i + 1) / 2) {
                    p1[i] = t;
                }
            }
        }

        mp.clear();
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++;
            if (mp[arr[i]] > (i + 1) / 2) {
                p2[i] = arr[i];
            } else {
                int t = p2[i - 1];
                if (mp[t] > (i + 1) / 2) {
                    p2[i] = t;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (p1[i] == p2[n - i - 2] && p1[i] != -1) {
                return i;
            }
        }

        return -1;
    }
};