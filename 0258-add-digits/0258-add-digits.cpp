class Solution {
public:
    int length(int num){
        if (num == 0) return 1;

        int ans = 0;
        while (num){
            num = num/10;
            ans++;
        }
        return ans;
    }

    int sumOfDigit(int num){
        int ans = 0;
        while (num){
            ans += num%10;
            num = num/10;
        }
        return ans;
    }

    int addDigits(int num) {
        int n = num;
        while (length(n) != 1){
            n = sumOfDigit(n);
        }
        return n;
    }
};