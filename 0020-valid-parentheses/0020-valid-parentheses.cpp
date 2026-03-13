class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch : s){
            if (ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else {
                if (stk.empty()) return false;
                char tp = stk.top();
                stk.pop();
                if (ch == ')' && tp != '(') return false;
                if (ch == '}' && tp != '{') return false;
                if (ch == ']' && tp != '[') return false;
            }
        }
        return stk.empty();
    }
};