class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int, vector<int>> adj;

        for (auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indegree(n, 0);
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (indegree[u] == 0)
                q.push(u);
        }

        int visited = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return visited == n;
    }
};