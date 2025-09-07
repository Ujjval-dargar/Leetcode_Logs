class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int low = -n / 2;
        int high = n / 2;
        for (int i = low; i <= high; ++i) {
            if (i == 0)
                continue;
            ans.push_back(i);
        }

        if (n % 2)
            ans.push_back(0);
        return ans;
    }
};