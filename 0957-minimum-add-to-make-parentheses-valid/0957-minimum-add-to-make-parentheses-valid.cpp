class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;

        int ans = 0;
        for (char ch:s){
            if (ch=='(') stk.push(ch);
            else{
                if (!stk.empty()) stk.pop();
                else ans++;
            }
        }

        return ans + stk.size();
    }
};