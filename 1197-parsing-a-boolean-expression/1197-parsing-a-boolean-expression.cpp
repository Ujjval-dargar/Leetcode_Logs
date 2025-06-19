class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;

        int n = expression.size();
        for (int i = 0; i < n; ++i) {
            char curr = expression[i];

            if (curr == '(' || curr == ',') continue;
            else if (curr == 't' || curr == 'f' || curr == '!' || curr == '|' || curr == '&') s.push(curr);
            else if (curr == ')') {

                bool anyTrue = false;
                bool anyFalse = false;

                while (s.top() != '!' && s.top() != '|' && s.top() != '&') {

                    if (s.top() == 'f') anyFalse = true;
                    else if (s.top() == 't') anyTrue = true;
                    s.pop();
                }

                char op = s.top();
                s.pop();

                if (op == '!') {
                    if (anyTrue) s.push('f');
                    else if (anyFalse) s.push('t');
                }
                else if (op == '|') {
                    if (anyTrue) s.push('t');
                    else s.push('f');
                } 
                else if (op == '&') {
                    if (anyFalse) s.push('f');
                    else s.push('t');
                }
            }
        }

        return s.top() == 't';
    }
};