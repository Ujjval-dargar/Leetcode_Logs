class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();

        int old = image[sr][sc];

        if (old == color)
            return image;

        vector<vector<int>> dirn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));
        queue<vector<int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        while (!q.empty()) {
            vector<int> tp = q.front();
            q.pop();
            int i = tp[0];
            int j = tp[1];
            visited[i][j] = true;

            for (int k = 0; k < 4; ++k) {
                int ni = i + dirn[k][0];
                int nj = j + dirn[k][1];

                if (isValid(ni,nj,m,n) && !visited[ni][nj] && image[ni][nj] == old){
                    image[ni][nj] = color;
                    q.push({ni,nj});
                }
            }
        }

        return image;
    }
};