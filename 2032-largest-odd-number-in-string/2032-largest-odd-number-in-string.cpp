class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        int i = n - 1;
        for (; i >= 0; --i) {
            if ((num[i] - '0') % 2)
                break;
        }

        if (i == -1)
            return "";

        string ans;
        for (int j = 0; j <= i; ++j) {
            ans.push_back(num[j]);
        }
        return ans;
    }
};