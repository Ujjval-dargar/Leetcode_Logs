class Solution {
public:
    bool backtrack(vector<int>& ans, vector<bool>& used, int n, int index) {
        if (index == ans.size()) {
            return true;
        }

        if (ans[index] != 0) {
            return backtrack(ans, used, n, index + 1);
        }

        for (int num = n; num >= 1; num--) {
            if (!used[num]) {
                
                if (num == 1) {
                    ans[index] = num;
                    used[num] = true;
                } 
                else {
                    int nextIndex = index + num;

                    if (nextIndex < ans.size() && ans[nextIndex] == 0) {
                        ans[index] = num;
                        ans[nextIndex] = num;
                        used[num] = true;
                    } 
                    else {
                        continue;
                    }
                }

                if (backtrack(ans, used, n, index + 1)) {
                    return true;
                }

                ans[index] = 0;
                if (num == 1) {
                    used[num] = false;
                } else {
                    int nextIndex = index + num;
                    ans[nextIndex] = 0;
                    used[num] = false;
                }
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(ans, used, n, 0);
        return ans;
    }
    
};