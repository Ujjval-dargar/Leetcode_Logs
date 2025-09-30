class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;

        int n = points.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {

                    double x1 = points[i][0];
                    double x2 = points[j][0];
                    double x3 = points[k][0];

                    double y1 = points[i][1];
                    double y2 = points[j][1];
                    double y3 = points[k][1];

                    double curr = 0.5 * (x1 * (double)(y2 - y3) + x2 * (double)(y3 - y1) +
                                         x3 * (double)(y1 - y2));

                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};