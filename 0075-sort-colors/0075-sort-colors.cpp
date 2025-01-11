class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = -1;
        int r = n;

        int i = 0;
        while (i < r) {
            if (nums[i] == 0) {
                l++;

                nums[i] = nums[l];
                nums[l] = 0;

            } else if (nums[i] == 2) {
                r--;

                nums[i] = nums[r];
                nums[r] = 2;

                i--;
            }

            i++;
        }
    }
};