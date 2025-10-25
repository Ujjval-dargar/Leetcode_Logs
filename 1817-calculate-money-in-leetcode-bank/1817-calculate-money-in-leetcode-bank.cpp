class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks = n/7;
        int rem = n % 7;

        int ans = 0;
        ans = 28 * fullWeeks + (fullWeeks * (fullWeeks-1)*7)/2;
        ans += (rem*(rem+1))/2 + fullWeeks*rem;
        return ans;
    }
};