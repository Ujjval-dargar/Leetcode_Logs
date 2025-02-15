vector<int> v(1001,0);
bool f=false;
class Solution {
public:

    bool canPartition(string s, int target) {
        if (s == "" && target == 0) return true;
        if (target < 0) return false;
        bool ans = false;
        for (int i = 0; i < min(4,(int)s.size()); i++) {
            string left = s.substr(0, i + 1);
            string right = s.substr(i + 1);
            int leftNum = stoi(left);

            bool isPossible = canPartition(right, target - leftNum);
            if (isPossible) {
                ans = true;
                break;
            }
        }
        return ans;
    }
    void fill(){
        int sum = 0;
        for (int num = 1; num <= 1000; num++) {
            int sqr = num * num;
            if (canPartition(to_string(sqr), num)) {
                sum += sqr;
            }
            v[num]=sum;
        }
        f=true;
    }
    int punishmentNumber(int n) {
        if(!f){
            fill();           
        }
        return v[n];
    }
};