class Solution {
public:
    int maxScore(string s) {

        int n = s.size();

        vector<int> freq0(n);
        vector<int> freq1(n);

        int cnt0 = 0;
        int cnt1 = 0;
        int i = 0;
        int j = 0;

        for (char chr : s) {
            if (chr == '0')
                cnt0++;
            else
                cnt1++;

            freq0[i] = cnt0;
            i++;
            freq1[j] = cnt1;
            j++;
        }

        if (cnt1 == 0)
            return cnt0 - 1;
        else if (cnt0 == 0)
            return cnt1 - 1;

        int ans = 0;
        for (int i = 0; i < n-1; ++i) {
            cout << freq0[i] << ":" << freq1[i] << endl;
            ans = max(ans, freq0[i] + cnt1 - freq1[i]);
        }

        return ans;
    }
};