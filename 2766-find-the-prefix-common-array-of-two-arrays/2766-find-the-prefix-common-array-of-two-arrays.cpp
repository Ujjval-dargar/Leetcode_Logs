class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, bool> mp;
        int n = A.size();
        vector<int> c(n, 0);

        if (A[0] == B[0]) {
            c[0] = 1;
            mp[A[0]] = true;
        } else {
            mp[A[0]] = true;
            mp[B[0]] = true;
        }

        for (int i = 1; i < n; ++i) {
            if (A[i] == B[i]) {
                c[i] = 1 + c[i - 1];
                mp[A[i]] = true;
            } else {
                if (mp[A[i]] && mp[B[i]]) {
                    c[i] = 2 + c[i - 1];
                } else if (mp[A[i]] || mp[B[i]]) {
                    c[i] = 1 + c[i - 1];
                } else {
                    c[i] = c[i - 1];
                }

                mp[A[i]] = true;
                mp[B[i]] = true;
            }
        }

        return c;
    }
};