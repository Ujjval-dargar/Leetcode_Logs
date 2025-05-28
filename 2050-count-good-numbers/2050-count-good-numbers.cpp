#define ll long long

class Solution {
public:
    ll power(ll x, ll n) {
        if (n == 0 || x == 1) {
            return 1;
        }

        ll half = power(x, n / 2);
        if (n % 2 == 0)
            return (half % (1000000007) * half % (1000000007)) % 1000000007;

        return (half % (1000000007) * half % (1000000007) * x % 1000000007) %
               1000000007;
    }

    int countGoodNumbers(long long n) {
        ll mod = 1000000007;
        ll even = ceil((double)n / 2.0);
        ll odd = n - even;
        return (power(5, even) % mod * power(4, odd) % mod) % mod;
    }
};