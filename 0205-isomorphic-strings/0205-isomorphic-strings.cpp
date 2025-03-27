class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> arr(26, -1);
        vector<int> visited(26, false);

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (arr[s[i] - 'a'] != -1) {

                if (arr[s[i] - 'a'] != t[i] - 'a') {
                    return false;
                } else {
                    continue;
                }
            }

            if (visited[t[i] - 'a'])
                return false;

            arr[s[i] - 'a'] = t[i] - 'a';
            visited[t[i] - 'a'] = true;
        }

        return true;
    }
};