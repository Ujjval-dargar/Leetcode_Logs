class Solution {
public:
    // int f(vector<int>& cuts, int i, int j, vector<vector<int>>& mem) {
    //     if (i > j)
    //         return 0;

    //     if (mem[i][j] != -1)
    //         return mem[i][j];

    //     int mnCost = INT_MAX;
    //     for (int k = i; k <= j; ++k) {
    //         int currCost = cuts[j + 1] - cuts[i - 1] + f(cuts, i, k - 1, mem)
    //         +
    //                        f(cuts, k + 1, j, mem);
    //         mnCost = min(mnCost, currCost);
    //     }

    //     return mem[i][j] = mnCost;
    // }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int sz = cuts.size();

        vector<vector<int>> mem(sz, vector<int>(sz, 0));

        for (int i = sz - 2; i >= 1; --i) {
            for (int j = 1; j <= sz - 2; ++j) {
                if (i > j)
                    continue;

                int mnCost = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int currCost = cuts[j + 1] - cuts[i - 1] +
                                   mem[i][k - 1] +
                                   mem[k + 1][j];
                    mnCost = min(mnCost, currCost);
                }

                mem[i][j] = mnCost;
            }
        }

        return mem[1][sz - 2];
    }
};