class Solution {
public:
    bool check(long long mid, int h, vector<int>& workerTimes){
        
        for (int t : workerTimes){
            if (h <= 0) return true;

            long double val = (long double)2 * mid / t;
            long long x = (sqrtl(1 + 4 * val) - 1) / 2;

            h -= x;
        }

        return h <= 0;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0;
        long long r = 1e18;

        long long ans = r;

        while (l <= r){
            long long mid = l + (r - l) / 2;

            if (check(mid, mountainHeight, workerTimes)){
                ans = mid;
                r = mid - 1;
            } 
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};