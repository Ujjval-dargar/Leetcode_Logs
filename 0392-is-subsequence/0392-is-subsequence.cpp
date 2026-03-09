class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int j = 0;
        for (char ch : t){
            if (ch == s[j]) j++;
        }
        return j == n;
    }
};