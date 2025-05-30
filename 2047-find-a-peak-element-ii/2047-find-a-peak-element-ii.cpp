class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0;
        int r = m - 1;

        while (l <= r) {
            int mid = (r - l) / 2 + l;

            int mx = INT_MIN;
            int idx = -1;
            for (int i = 0; i < n; ++i) {
                if (mat[i][mid] > mx) {
                    mx = mat[i][mid];
                    idx = i;
                }
            }

            int left = (mid-1 >= 0) ? mat[idx][mid - 1] : 0;
            int right = (mid+1 < m) ? mat[idx][mid + 1] : 0;

            if (mat[idx][mid] > left && mat[idx][mid] > right) {
                return {idx, mid};
            } else if (mat[idx][mid] < left) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return {-1, -1};
    }
};