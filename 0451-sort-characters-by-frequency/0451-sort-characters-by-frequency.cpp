class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> freq(256, 0);
        for (int i = 0; i < n; ++i) {
            freq[s[i]]++;
        }

        vector<pair<int, int>> arr;
        for (int i = 0; i < 256; ++i) {
            if (freq[i] != 0) {
                arr.push_back({freq[i], i});
            }
        }

        sort(arr.rbegin(), arr.rend());

        string ans;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[i].first; ++j) {
                ans.push_back(arr[i].second);
            }
        }

        return ans;
    }
};