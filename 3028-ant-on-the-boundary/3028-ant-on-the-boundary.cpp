class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int sm = 0;
        int ans = 0;
        for (int i : nums){
            sm += i;
            if (sm == 0) ans++;
        }
        return ans;
    }
};