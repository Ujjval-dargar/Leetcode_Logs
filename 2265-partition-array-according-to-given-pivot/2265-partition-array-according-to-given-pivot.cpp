class Solution {
public:
    void swap(vector<int>& arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;
        vector<int> arr3;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                arr1.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                arr2.push_back(nums[i]);
            } else {
                arr3.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for (int i : arr1) {
            ans.push_back(i);
        }
        for (int i : arr2) {
            ans.push_back(i);
        }
        for (int i : arr3) {
            ans.push_back(i);
        }

        return ans;
    }
};