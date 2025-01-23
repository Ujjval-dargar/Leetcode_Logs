class Solution {
public:

    int countPairs(vector<int>& arr, int start, int mid, int end) {

        int ans =0;
        int j = mid + 1;
        for (int i = start; i <= mid; ++i) {

            while (j <= end && arr[i] > 2ll * arr[j]) {
                j++;
            }

            ans += j - (mid + 1);
        }

        return ans;
    }

    void merge(vector<int>& arr, int start, int mid, int end) {
        vector<int> temp;

        int i = start;
        int j = mid + 1;

        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        int n = temp.size();
        for (int i = 0; i < n; ++i) {
            arr[start + i] = temp[i];
        }
    }

    int mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end)
            return 0;

        int mid = (start + end) / 2;

        int a1 = mergeSort(arr, start, mid);
        int a2 = mergeSort(arr, mid + 1, end);

        int a3 = countPairs(arr, start, mid, end);

        merge(arr, start, mid, end);

        return a1 + a2 + a3;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int ans = mergeSort(nums, 0, n - 1);

        return ans;
    }
};