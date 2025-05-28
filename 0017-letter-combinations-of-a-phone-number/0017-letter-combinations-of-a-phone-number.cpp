class Solution {
public:
    void f(string digits, int i, string curr, vector<string>& ans,
           unordered_map<char, vector<string>>& mp) {

        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        char ch = digits[i];
        for (string s : mp[ch]) {
            f(digits, i + 1, curr + s, ans, mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};

        unordered_map<char, vector<string>> mp;
        mp['1'] = {};
        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};
        mp['0'] = {};

        vector<string> ans;
        f(digits, 0, "", ans, mp);
        return ans;
    }
};