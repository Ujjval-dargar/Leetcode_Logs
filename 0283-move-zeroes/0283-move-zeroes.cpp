class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;
        int j = 0;
        int n = nums.size();

        while (j < n) {
            if (nums[j] != 0) {
                i++;
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                ;
            }

            j++;
        }
    }
};