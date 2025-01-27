class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &mp, int src, int end,
             vector<bool>& visited) {
        visited[src] = true;
        if (src == end)
            return true;

        for (int i : mp[src]) {
            if (!visited[i] && dfs(mp, i, end, visited))
                return true;
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& arr,
                                     vector<vector<int>>& q) {

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i][0]].push_back(arr[i][1]);
        }

        vector<bool> ans;
        int m = q.size();
        for (int i = 0; i < m; ++i) {
            vector<bool> visited(n, false);
            ans.push_back(dfs(mp, q[i][0], q[i][1], visited));
        }

        return ans;
    }
};