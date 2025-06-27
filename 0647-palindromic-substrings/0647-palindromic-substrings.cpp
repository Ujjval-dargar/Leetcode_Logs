class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }

    int f(string& s, int i, int j, vector<vector<int>> &mem) {

        int n = s.size();
        if (i >= n)
            return 0;

        if (j >= n)
            return f(s, i + 1, i + 1, mem);

        if (mem[i][j]!=-1) return mem[i][j];

        int cnt = isPal(s, i, j) ? 1 : 0;

        cnt += f(s, i, j + 1, mem);

        return mem[i][j] = cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, -1));
        return f(s, 0, 0, mem);
    }
};