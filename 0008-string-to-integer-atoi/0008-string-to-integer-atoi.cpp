class Solution {
public:
    int myAtoi(string s) {

        int mx = ((long)(1 << 31) - 1);
        int mn = (-1 * (long)(1 << 31));
        long ans = 0;

        int sign = 1;

        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ')
            i++;
        if (i >= n)
            return ans;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int t = s[i] - '0';
            ans = ans * 10 + t;
            cout << ans * sign << endl;
            if (ans * sign > mx) {
                cout << mx << endl;
                ans = mx;
                break;
            } else if (ans * sign < mn) {
                ans = mn;
                break;
            }
            i++;
        }
        return sign * ans;
    }
};