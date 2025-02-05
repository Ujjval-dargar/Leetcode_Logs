class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> temp;

        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i])
                temp.push_back(i);
        }

        if (temp.size() == 0)
            return true;
        else if (temp.size() == 2) {
            int i = temp[0];
            int j = temp[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        } else {
            return false;
        }
    }
};