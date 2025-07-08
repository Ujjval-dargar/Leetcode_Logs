class Solution {
public:
    bool valid(string& str1, string& str2, int len) {
        int s1 = str1.size();
        int s2 = str2.size();
        if (s1 % len != 0 || s2 % len != 0)
            return false;

        int a = s1 / len;
        int b = s2 / len;
        string part = str1.substr(0, len);

        string temp1;
        string temp2;

        for (int i = 0; i < a; ++i) temp1 += part;
        for (int i = 0; i < b; ++i) temp2 += part;

        return temp1 == str1 && temp2 == str2;
    }

    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();

        string ans = "";
        for (int len = min(s1, s2); len >= 1; --len) {
            if (valid(str1, str2, len)) {
                ans = str1.substr(0, len);
                break;
            }
        }

        return ans;
    }
};