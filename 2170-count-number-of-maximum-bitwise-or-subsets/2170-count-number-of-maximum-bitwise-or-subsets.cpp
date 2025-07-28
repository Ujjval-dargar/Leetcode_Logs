class Solution {
public:
    int mx = 0;
    int cnt = 0;

    void f(vector<int>& nums, int curr, int i) {
        int n = nums.size();
        if (i == n) {
            if (curr > mx){
                mx = curr;
                cnt = 1;
            }
            else if (curr == mx){
                cnt++;
            }

            return;
        }

        f(nums, curr | nums[i], i + 1);
        f(nums, curr, i + 1);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        f(nums, 0, 0);
        return cnt;
    }
};