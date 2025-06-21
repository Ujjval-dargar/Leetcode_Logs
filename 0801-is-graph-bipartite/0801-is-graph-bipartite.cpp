class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color, int curr) {
        color[u] = curr;

        for (int v:graph[u]){
            if (color[v]==-1){
                if (!dfs(v,graph,color,!curr)) return false;
            }
            else if (color[v]==curr) return false; 
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!dfs(i, graph, color, 0))
                    return false;
            }
        }

        return true;
    }
};