class Solution {
public:
    bool isPowerOfFour(int n) {

        if (n == 1)
            return true;
        if (n <= 3)
            return false;
        int cnt = __builtin_popcount(n);

        if (cnt > 1) {
            return false;
        }

        bitset<32> bin_num = (bitset<32>(n));
    
        int pos = -1;
        for (int i = 31; i >= 0; --i) {
            if (bin_num[i] == 1 && !(i % 2)) {
                pos = i;
                break;
            }
        }
        return !(pos % 2);
    }
};