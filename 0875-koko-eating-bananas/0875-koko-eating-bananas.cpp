class Solution {
public:
    bool check(vector<int>& piles, int h, int k){
        int time = 0;
        int n = piles.size();
        for (int i = 0; i < n; ++i){
            int e = piles[i];
            time += e/k;
            if (e % k){
                time += 1;
            }
            if (time > h) return false;
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = -1;
        while (l <= r){
            int m = (r-l)/2 + l;
            if (check(piles, h, m)){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }

        return ans;
    }
};