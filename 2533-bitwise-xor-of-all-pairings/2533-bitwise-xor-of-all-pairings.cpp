class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 % 2 == 0 && n2 % 2 == 0)
            return ans;

        if (n2 % 2) {
            for (int i = 0; i < n1; ++i) {
                ans = ans ^ nums1[i];
            }
        }

        if (n1 % 2) {
            for (int i = 0; i < n2; ++i) {
                ans = ans ^ nums2[i];
            }
        }

        return ans;
    }
};