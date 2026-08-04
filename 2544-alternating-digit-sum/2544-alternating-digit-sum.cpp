class Solution {
public:

    int alternateDigitSum(int n) {
        int l = to_string(n).size();
        int sign = -1;
        if (l%2) sign = +1;

        int ans = 0;
        while (n){
            int d = n % 10;
            n = n/10;
            ans = ans + sign*d;
            sign = sign * (-1);
        }
        return ans;
    }
};