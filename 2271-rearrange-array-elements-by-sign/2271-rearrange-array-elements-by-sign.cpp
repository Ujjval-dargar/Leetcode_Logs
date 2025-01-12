class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;

        int l = 0;
        int r = 0;
        while (l < n && r < n) {
            while (nums[l] < 0) {
                l++;
            }
            while (nums[r] > 0) {
                r++;
            }
            arr.push_back(nums[l]);
            arr.push_back(nums[r]);
            l++;
            r++;
        }

        return arr;
    }
};