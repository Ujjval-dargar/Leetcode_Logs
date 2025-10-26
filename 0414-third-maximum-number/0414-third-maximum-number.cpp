class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long f = LLONG_MIN;
        long long s = LLONG_MIN;
        long long t = LLONG_MIN;

        for (int num : nums){
            if (f == num || s == num || t == num) continue;
            if (f < num){
                t = s;
                s = f;
                f = num;
            }
            else if (s < num){
                t = s;
                s = num;
            }
            else if (t < num){
                t = num;
            }
        }

        if (t == LLONG_MIN){
            return f;
        }
        return t;
    }
};