class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> nextGreater(n, -1);
        stack<int> stk;
        for (int i = n-1 ; i >= 0 ; --i){
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }

            if (!stk.empty()) nextGreater[i] = stk.top();
            stk.push(i);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i){
            if (nextGreater[i] != -1) {
                ans[i] = nextGreater[i] - i;
            }
            else {
                ans[i] = 0;
            }
        }

        return ans;


    }
};