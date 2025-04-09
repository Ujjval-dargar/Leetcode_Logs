class Solution {
public:
    vector<pair<int, char>> helper1(string s) {

        int cnt = 0;
        char ele = '0';

        vector<pair<int, char>> ans;

        for (int i = 0; i < s.size(); ++i) {
            if (i == 0) {
                ele = s[0];
                cnt++;
            } else {
                if (s[i] == ele) {
                    cnt++;
                } else {
                    ans.push_back({cnt, ele});
                    ele = s[i];
                    cnt = 1;
                }
            }
        }
        ans.push_back({cnt, ele});

        return ans;
    }

    string helper2(vector<pair<int, char>> arr) {
        string s = "";
        for (auto i : arr) {
            s.push_back('0' + i.first);
            s.push_back(i.second);
        }

        return s;
    }

    string countAndSay(int n) {

        string ans = "1";
        if (n == 1) {
            return ans;
        }

        for (int i = 0; i < n - 1; ++i) {
            ans = helper2(helper1(ans));
        }

        return ans;
    }
};