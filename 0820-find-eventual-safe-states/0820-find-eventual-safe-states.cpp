class Solution {
public:
    vector<int> visited;
    vector<int> curr;

    bool dfs(int u, vector<vector<int>>& graph) {
        if (curr[u])
            return true;
        if (visited[u])
            return false;

        visited[u] = true;
        curr[u] = true;

        for (int v : graph[u]) {
            if (dfs(v, graph))
                return true;
        }

        curr[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        visited.resize(n, false);
        curr.resize(n, false);

        vector<int> ans;
        for (int u = 0; u < n; ++u) {
            if (!dfs(u, graph))
                ans.push_back(u);
        }

        return ans;
    }
};