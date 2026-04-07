class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt_u = 0;
        int cnt_d = 0;
        int cnt_l = 0;
        int cnt_r = 0;

        for (char ch : moves){
            if (ch == 'U') cnt_u++;
            else if (ch == 'L') cnt_l++;
            else if (ch == 'R') cnt_r++;
            else if (ch == 'D') cnt_d++;
        }

        return cnt_u == cnt_d && cnt_l == cnt_r;
    }
};