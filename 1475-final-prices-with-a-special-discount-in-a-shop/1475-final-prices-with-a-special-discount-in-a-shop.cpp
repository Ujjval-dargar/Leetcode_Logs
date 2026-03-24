class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> nextSmaller(n,-1);
        
        stack<int> stk;
        for (int i = n-1; i >=0; --i){
            while (!stk.empty() && stk.top() > prices[i]){
                stk.pop();
            }
            if (!stk.empty()){
                nextSmaller[i] = stk.top();
            }

            stk.push(prices[i]);
        }

        // for (int i = 0; i < n; ++i){
        //     cout << nextSmaller[i] << " ";
        // }

        vector<int> ans(n,0);
        for (int i = 0; i < n; ++i){
            ans[i] = prices[i];
            if (nextSmaller[i] != -1) ans[i] -= nextSmaller[i];
        }
        return ans;
    }
};