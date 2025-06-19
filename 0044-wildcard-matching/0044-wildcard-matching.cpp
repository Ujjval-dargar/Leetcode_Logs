class Solution {
public:
    // bool f(string& s, string& p, int i, int j, vector<vector<int>>& mem) {

    //     int n1 = s.size();
    //     int n2 = p.size();
    //     if (i == n1 && j == n2)
    //         return true;
    //     if (j == n2)
    //         return false;
    //     if (i == n1) {
    //         for (int k = j; k < n2; ++k) {
    //             if (p[k] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     if (p[j] == '*') {
    //         return mem[i][j] = f(s, p, i, j + 1, mem) || f(s, p, i + 1, j, mem);

    //     } else if (p[j] == '?') {
    //         return mem[i][j] = f(s, p, i + 1, j + 1, mem);
    //     } else {
    //         if (s[i] != p[j])
    //             return false;
    //         return mem[i][j] = f(s, p, i + 1, j + 1, mem);
    //     }
    // }

    bool isAllStar(string& p, int j) {
        int n = p.size();
        for (int k = j; k < n; ++k) {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1; i >= 0; --i) {
            for (int j = n2; j >= 0; --j) {

                if (i == n1 && j == n2) { mem[i][j] = true; continue; }
                if (j == n2) { mem[i][j] = false; continue; }
                if (i == n1) { mem[i][j] = isAllStar(p,j); continue; }

                if (p[j] == '*') mem[i][j] = mem[i][j + 1] || mem[i + 1][j];

                else if (p[j] == '?') mem[i][j] = mem[i + 1][j + 1];
                
                else {
                    if (s[i] != p[j]) mem[i][j] = false;
                    else mem[i][j] = mem[i + 1][j + 1];
                }
            }
        }
        return mem[0][0];
    }
};