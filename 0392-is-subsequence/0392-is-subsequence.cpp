class Solution {
public:
    bool f(string& s1, string& s2, int i, int j, vector<vector<int>>& mem) {

        int n1 = s1.size();
        int n2 = s2.size();

        if (i == n1)
            return true;

        if (j == n2)
            return false;

        if (mem[i][j] != -1)
            return mem[i][j];

        if (s1[i] == s2[j]) {
            return mem[i][j] = f(s1, s2, i + 1, j + 1, mem);
        } else {
            return mem[i][j] = f(s1, s2, i, j + 1, mem);
        }
    }

    bool isSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1, -1));

        return f(s1, s2, 0, 0, mem);
    }
};