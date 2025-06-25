class Solution {
public:
    bool isValid(int i, int j, int n) {
        return (i >= 0 && j >= 0 && i < n && j < n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dirn = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            vector<int> v = pq.top();
            pq.pop();

            int curr = v[0];
            int i = v[1];
            int j = v[2];

            if (i == n - 1 && j == n - 1) {
                return curr;
            }

            if (visited[i][j])
                continue;
            visited[i][j] = true;

            for (auto& d : dirn) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (isValid(ni, nj, n) && !visited[ni][nj]) {
                    pq.push({max(curr, grid[ni][nj]), ni, nj});
                }
            }
        }

        return -1;
    }
};