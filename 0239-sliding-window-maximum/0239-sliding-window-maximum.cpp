class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        vector<int> ans;

        deque<int> dq;
        while (r < n) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            while (l <= r && r - l + 1 > k) {
                if (!dq.empty() && dq.front() == l) {
                    dq.pop_front();
                }
                l++;
            }

            if (r - l + 1 == k) {
                ans.push_back(nums[dq.front()]);
            }

            r++;
        }

        return ans;
    }
};