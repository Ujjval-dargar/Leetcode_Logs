class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq(
            nums.begin(), nums.end());

        long long a = pq.top();
        while (a < k) {
            pq.pop();
            long long b = pq.top();
            pq.pop();

            ans++;
            pq.push(min(a, b) * 2 + max(a, b));

            a = pq.top();
        }

        return ans;
    }
};