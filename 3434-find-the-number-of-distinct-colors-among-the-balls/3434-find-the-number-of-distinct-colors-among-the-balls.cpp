class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> color;

        int n = queries.size();

        vector<int> ans;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (mp[b] == 0) {
                cnt++;
            }

            if (color[a] == 0) {
                mp[b]++;
            } else if (color[a] != b) {
                mp[color[a]]--;
                if (mp[color[a]] == 0) {
                    cnt--;
                }
                mp[b]++;
            }

            color[a] = b;
            ans.push_back(cnt);
        }

        return ans;
    }
};