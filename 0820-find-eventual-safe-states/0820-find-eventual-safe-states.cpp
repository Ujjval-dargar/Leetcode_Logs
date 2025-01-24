class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& state) {
        if (state[node] == 1)
            return false;
        else if (state[node] == 2)
            return true;

        state[node] = 1;
        for (int i : graph[node]) {
            if (!dfs(graph, i, state)) {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> state(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (dfs(graph, i, state)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};