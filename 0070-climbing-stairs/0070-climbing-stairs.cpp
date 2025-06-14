class Solution {
public:
    int climbStairs(int n) {

        if (n <= 3)
            return n;

        int t1 = 1;
        int t2 = 2;
        int t3 = 3;
        for (int i = 4; i <= n; ++i) {
            int temp = t2 + t3;
            swap(t1, t2);
            t2 = t3;
            t3 = temp;
        }

        return t3;
    }
};