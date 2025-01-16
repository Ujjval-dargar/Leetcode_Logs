class Solution {
public:
    int findLow(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == target) {
                if ((mid - 1 >= 0 && nums[mid - 1] != target) || mid == 0)
                    return mid;
                else
                    high = mid - 1;
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int findHigh(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == target) {
                if ((mid + 1 < n && nums[mid + 1] != target) || mid == n-1) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {findLow(nums, target), findHigh(nums, target)};
    }
};