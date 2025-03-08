class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = 0;

        // if (k==1){
        //     for (int i=0;i<n;++i){
        //         if (blocks[i]=='B')return 0;
        //     }
        //     return 1;
        // }

        for (int i = 0; i < k; ++i) {
            ans += blocks[i] == 'W';
        }

        int i = 0;
        int j = k - 1;
        int t = ans;
        while (j < n - 1) {

            cout << i << " " << j << " " << ans << endl;
            if (blocks[i] == 'W') t--;
            if (blocks[j + 1] == 'W') t++;
            ans = min(ans, t);
            i++;
            j++;
        }

        return ans;
    }
};