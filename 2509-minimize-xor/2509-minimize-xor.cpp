class Solution {
public:
    vector<int> binary(int n) {
        vector<int> ans;
        while (n > 0) {
            int r = n % 2;
            n = n / 2;
            ans.push_back(r);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    int number(vector<int> a) {
        int ans = 0;
        int n = a.size();
        for (int i = n - 1; i >= 0; --i) {
            ans += a[i] * pow(2, n - i - 1);
        }
        return ans;
    }

    int countSetBits(vector<int>& a) {
        int ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i])
                ans++;
        }
        return ans;
    }

    int minimizeXor(int num1, int num2) {
        vector<int> n1 = binary(num1);
        vector<int> n2 = binary(num2);

        int c1 = countSetBits(n1);
        int c2 = countSetBits(n2);

        cout << c1 << " " << c2 << endl;

        if (c1 == c2)
            return num1;
        else if (c1 > c2) {
            int i = n1.size() - 1;
            while (c1 != c2) {
                if (n1[i]) {
                    n1[i] = 0;
                    c1--;
                }
                i--;
            }
        } else {
            int i = n1.size() - 1;
            while (c1 != c2 && i >= 0) {
                if (n1[i] == 0) {
                    n1[i] = 1;
                    c1++;
                }
                i--;
            }
        }
        // cout << c1 << " " << c2 << endl;
        if (c1 != c2) {
            int t = c2 - c1;
            for (int i = 0; i < t; ++i) {
                n1.push_back(1);
            }
        }
        return number(n1);
    }
};