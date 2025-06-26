class Solution {
public:
    vector<int> diStringMatch(string s) {
        int high = s.size();
        int low = 0;

        vector<int> ans;

        for (char ch : s) {
            if (ch == 'I') {
                ans.push_back(low++);
            } else {
                ans.push_back(high--);
            }
        }

        ans.push_back(high);
        return ans;
    }
};