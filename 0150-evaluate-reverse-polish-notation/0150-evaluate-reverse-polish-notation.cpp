class Solution {
public:
    bool isOperator(string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            string str = tokens[i];
            if (isOperator(str)) {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                s.pop();

                int res = 0;
                if (str == "+")
                    res = t1 + t2;
                else if (str == "-")
                    res = t2 - t1;
                else if (str == "*")
                    res = t1 * t2;
                else if (str == "/")
                    res = t2 / t1;

                s.push(res);
            } else {
                s.push(stoi(str));
            }
        }

        return s.top();
    }
};