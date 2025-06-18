class Solution {
public:


    string shortestCommonSupersequence(string s1, string s2) {

        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1, 0));
        vector<vector<int>> dir(n1 + 1, vector<int>(n2 + 1, -1));

        for (int i = n1; i >= 0; --i){
            for (int j = n2; j >= 0; --j)
            {
                if (i == n1 && j == n2) continue;
                if (i == n1) {mem[i][j] = n2 - j; continue;}
                if (j == n2) {mem[i][j] = n1 - i; continue;}

                if (s1[i] == s2[j]) {
                    dir[i][j] = 0;
                    mem[i][j] = 1 + mem[i + 1][j + 1];
                    continue;
                }

                int op1 = 1 + mem[i][j + 1];
                int op2 = 1 + mem[i + 1][j];

                if (op1 <= op2) {
                    dir[i][j] = 2;
                    mem[i][j] = op1;
                } else {
                    dir[i][j] = 1;
                    mem[i][j] = op2;
                }                
            }
        }

        string ans;
        int i = 0;
        int j = 0;

        while (i < n1 || j < n2) {
            if (i == n1) ans.push_back(s2[j++]);
            else if (j == n2) ans.push_back(s1[i++]);
            else if (dir[i][j] == 0) {ans.push_back(s1[i++]); j++;} 
            else if (dir[i][j] == 1) ans.push_back(s1[i++]);
            else if (dir[i][j] == 2) ans.push_back(s2[j++]);
        }

        return ans;
    }
};