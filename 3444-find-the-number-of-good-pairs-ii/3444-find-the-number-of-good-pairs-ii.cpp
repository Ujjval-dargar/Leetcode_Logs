class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long, long long> mp1;
        unordered_map<long long, long long> mp2;
        for (long long i : nums1)
            mp1[i]++;

        for (long long i : nums2)
            mp2[i]++;

        long long mx = *max_element(nums1.begin(), nums1.end());
        long long ans = 0;

        for (auto i : mp2) {
            long long ele = i.first * k;
            long long freq = i.second;

            for (long long j = ele; j <= mx; j += ele) {
                if (mp1[j]) {
                    ans += mp1[j] * freq;
                }
            }
        }

        return ans;
    }
};