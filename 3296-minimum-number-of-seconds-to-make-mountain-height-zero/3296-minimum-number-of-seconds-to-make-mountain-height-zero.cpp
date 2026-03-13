class Solution {
public:
    bool check(long long mid, int h, vector<int>& workerTimes){
        
        int n = workerTimes.size();
        for (int i = 0; i < n; ++i){
            if (h <= 0) return true;
            long long t = workerTimes[i];
            long long val = (2 * mid) / t;
            long long x = (sqrt(1 + 4 * val) - 1) / 2;
            h -= x;
        }

        return h <= 0;   
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0;
        long long r = 1e18;

        long long ans;
        while (l <= r)
        {
            long long mid = (r - l)/2 + l;
            if (check(mid, mountainHeight, workerTimes)){
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};