#define ll long long

class Solution {
public:

    int binToArr(vector<int>& nums, int num) {
        int ans = 0;
        for (int i = 0; i < 13; ++i) {
            if ((num >> i) & 1) {
                ans = ans ^ nums[i];
            }
        }

        // cout<<ans<<endl;

        return ans;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        ll s = 1 << n;

        int ans = 0;
        for (ll i = 0; i < s; ++i) {
            ans = ans + binToArr(nums, i);
        }

        return ans;
    }
};