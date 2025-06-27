class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();

        for (int j = 0; j < n; ++j) {
            int l1 = 0;
            int r1 = 0;

            int l2 = 0;
            int r2 = 0;

            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j])
                    l1++;
                if (rating[i] > rating[j])
                    l2++;
            }

            for (int k = j + 1; k < n; ++k) {
                if (rating[j] < rating[k])
                    r1++;
                if (rating[j] > rating[k])
                    r2++;
            }

            ans += (l1 * r1) + (l2 * r2);
        }

        return ans;
    }
};