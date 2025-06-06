class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int i = 0;
        int val = 0;
        int prev = 0;
        bool first = false;

        while (i < n) {

            long long curr = 0;
            string op = "";

            while (i < n && s[i] == ' ') i++;

            if (i == n) break;

            if (!first) {

                while (i < n && isdigit(s[i])) {
                    curr = curr * 10 + s[i] - '0';
                    i++;
                }
                first = true;

                val = curr;
                prev = curr;

            } else {

                op.push_back(s[i++]);

                while (i < n && s[i] == ' ') i++;
                while (i < n && isdigit(s[i])) {
                    curr = curr * 10 + s[i] - '0';
                    i++;
                }

                if (op == "+") {
                    val = val + curr;
                    prev = curr;
                } else if (op == "-") {
                    val = val - curr;
                    prev = -curr;
                } else if (op == "*") {
                    val = (val - prev) + (prev * curr);
                    prev = prev * curr;
                } else if (op == "/") {
                    val = (val - prev) + prev / curr;
                    prev = prev / curr;
                }
            }
        }

        return val;
    }
};