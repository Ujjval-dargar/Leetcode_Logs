class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0;
        int j = 0;
        int k = 0;

        int s1 = word1.size();
        int s2 = word2.size();

        ans.resize(s1 + s2);
        while (i < s1 && j < s2) {
            ans[k++] = word1[i++];
            ans[k++] = word2[j++];
        }

        while (i < s1) {
            ans[k++] = word1[i++];
        }

        while (j < s2) {
            ans[k++] = word2[j++];
        }

        return ans;
    }
};