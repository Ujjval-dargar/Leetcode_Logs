class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> mem(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int take = 0;
                int notTake = 0;

                if (text1[i] == text2[j]) {
                    take = 1 + mem[i + 1][j + 1];
                }

                notTake = max(mem[i + 1][j], mem[i][j + 1]);

                mem[i][j] = max(take, notTake);
            }
        }

        return mem[0][0];
    }
};