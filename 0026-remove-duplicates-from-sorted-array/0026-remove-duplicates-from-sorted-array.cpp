class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        int r=1;
        int n=nums.size();

        while (r<n){
            if (nums[r]!=nums[l]){
                l++;
                nums[l]=nums[r];
            }

            r++;
        }

        return l+1;

    }
};