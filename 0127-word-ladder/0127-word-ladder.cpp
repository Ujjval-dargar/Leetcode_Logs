class Solution {
public:
    int checkDiff(string a, string b) {
        int n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        
        bool found = false;
        for (string temp:wordList){
            if (temp==endWord){
                found=true;
                break;
            }
        }

        if (!found)return 0;
        
        unordered_map<string, bool> visited;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        visited[beginWord] = true;

        while (!q.empty()) {
            string s = q.front().first;
            int l = q.front().second;
            q.pop();
            

            if (s == endWord) {
                return l;
            }

            for (string s1 : wordList) {
                if (!visited[s1] && checkDiff(s1, s) == 1) {
                    q.push({s1, l + 1});
                    visited[s1]=true;
                }
            }
        }
        return 0;
    }
};