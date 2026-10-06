class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i){
            if (s[i] == ')'){
                int t = stk.top();
                stk.pop();
                int curr = 0;
                if (t == 0){
                    curr = 1;
                }
                else {
                    curr = t*2;
                }
                if (stk.empty()){
                    ans += curr;
                }
                else {
                    int t2 = stk.top();
                    stk.pop();
                    stk.push(t2+curr);
                }
            }
            else {
                stk.push(0);
            }
        }
        while (!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};