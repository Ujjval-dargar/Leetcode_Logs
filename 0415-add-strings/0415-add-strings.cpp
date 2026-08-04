class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int c = 0;
        int i = n1-1;
        int j = n2-1;
        string ans;
        while (i >= 0 && j >= 0){
            int m = num1[i] - '0';
            int n = num2[j] - '0';
            int o = m + n + c;

            string t = to_string(o);
            if (t.size() == 2){
                ans.push_back(t[1]);
                c = t[0] - '0';
            }
            else {
                ans.push_back(o+'0');
                c = 0;
            }

            i--;
            j--;
            // cout << o << " "<<c<<" "<<t<<" " << ans << endl;
        }
        while (i >= 0){
            int m = num1[i]-'0';
            int o = m+c;
            string t = to_string(o);
            if (t.size() == 2){
                ans.push_back(t[1]);
                c = t[0] - '0';
            }
            else {
                ans.push_back(o+'0');
                c = 0;
            }

            i--;
        }
        while (j >= 0){
            int m = num2[j]-'0';
            int o = m+c;
            string t = to_string(o);
            if (t.size() == 2){
                ans.push_back(t[1]);
                c = t[0] - '0';
            }
            else {
                ans.push_back(o+'0');
                c = 0;
            }
            j--;
        }
        if (c) ans.push_back(c+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};