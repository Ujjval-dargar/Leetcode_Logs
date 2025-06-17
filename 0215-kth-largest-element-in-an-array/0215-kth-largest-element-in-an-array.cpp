class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            if ((int)(pq.size()) < k) {
                pq.push(nums[i]);
            } else {
                if (pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        return pq.top();
    }
};