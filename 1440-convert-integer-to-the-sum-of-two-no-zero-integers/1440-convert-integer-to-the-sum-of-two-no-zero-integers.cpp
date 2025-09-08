class Solution {
public:
    bool check(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);

        for (char ch : sa){
            if (ch == '0') return false;
        }
        for (char ch : sb){
            if (ch == '0') return false;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 0; i < n; ++i){
            int a = i;
            int b = n - a;
            if (check(a, b)){
                return {a,b};
            }
        }
        return {};
    }
};