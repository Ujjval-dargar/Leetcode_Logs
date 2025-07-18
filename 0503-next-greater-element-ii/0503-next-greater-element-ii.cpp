class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> s;
        for (int i = 0; i < 2*n; ++i) {
            
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                int prev = s.top();
                s.pop();

                ans[prev] = nums[i % n];
            }

            if (i < n) s.push(i);
        }
 
        return ans;
    }
};