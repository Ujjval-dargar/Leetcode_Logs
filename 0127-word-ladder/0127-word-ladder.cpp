class Solution {
public:
    bool diffby1(string& s1, string& s2) {
        int n = s1.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += s1[i] != s2[i];
            if (cnt > 1)
                return false;
        }

        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        bool found_begin = false;
        bool found_end = false;
        for (string s : wordList) {
            if (s == endWord)
                found_end = true;
            if (s == beginWord)
                found_begin = true;
        }

        if (!found_end)
            return 0;

        if (!found_begin)
            wordList.push_back(beginWord);

        int n = wordList.size();

        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && diffby1(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        visited[beginWord] = true;

        while (!q.empty()) {
            string u = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (u == endWord)
                return dist;

            for (string v : adj[u]) {
                if (!visited[v]) {
                    q.push({v, dist + 1});
                    visited[v] = true;
                }
            }
        }

        return 0;
    }
};