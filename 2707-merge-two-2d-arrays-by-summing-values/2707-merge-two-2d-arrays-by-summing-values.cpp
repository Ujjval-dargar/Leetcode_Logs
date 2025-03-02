class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {

        vector<int> temp(1001, 0);

        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i = 0; i < n1; ++i) {
            temp[nums1[i][0]] += nums1[i][1];
        }

        for (int i = 0; i < n2; ++i) {
            temp[nums2[i][0]] += nums2[i][1];
        }

        vector<vector<int>> ans;
        for (int i = 1; i <= 1000; ++i) {
            if (temp[i] != 0) {
                ans.push_back({i, temp[i]});
            }
        }
        return ans;
    }
};