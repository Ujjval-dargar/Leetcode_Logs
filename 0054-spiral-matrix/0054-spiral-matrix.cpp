class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int sr = 0;
        int sc = 0;
        int er = m - 1;
        int ec = n - 1;

        int total = m * n;
        int cnt = 0;

        while (cnt < total) {

            for (int i = sc; i <= ec && cnt < total; ++i) {
                ans.push_back(matrix[sr][i]);
                cnt++;
            }
            sr++;

            for (int i = sr; i <= er && cnt < total; ++i) {
                ans.push_back(matrix[i][ec]);
                cnt++;
            }
            ec--;

            for (int i = ec; i >= sc && cnt < total; --i) {
                ans.push_back(matrix[er][i]);
                cnt++;
            }
            er--;

            for (int i = er; i >= sr && cnt < total; --i) {
                ans.push_back(matrix[i][sc]);
                cnt++;
            }
            sc++;
        }

        return ans;
    }
};