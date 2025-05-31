class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (mid % 2)
                mid--;
            if (nums[mid] == nums[mid + 1])
                l = mid + 2;
            else
                r = mid;
        }

        return nums[l];
    }
};