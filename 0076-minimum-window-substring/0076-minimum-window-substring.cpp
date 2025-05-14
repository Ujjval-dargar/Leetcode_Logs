class Solution {
public:
    bool check(vector<int>& temp, vector<int>& cnt) {
        for (int i = 0; i < 128; ++i) {
            if (temp[i] > cnt[i]) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();

        int l = 0;
        int r = 0;
        vector<int> temp(128, 0);
        vector<int> cnt(128, 0);

        for (char c : t) {
            temp[c]++;
        }

        int mn = INT_MAX;
        int mnL = -1;

        while (r < n) {
            cnt[s[r]]++;

            while (l <= r && check(temp, cnt)) {
                if (mn > r - l + 1) {
                    mn = r - l + 1;
                    mnL = l;
                }
                cnt[s[l]]--;
                l++;
            }

            r++;
        }

        if (mnL == -1)
            return "";
        return s.substr(mnL, mn);
    }
};