class Solution {
public:
    vector<int> count(int num) {
        vector<int> arr(10);

        int a = num % 10;
        num = num / 10;

        int b = num % 10;
        num = num / 10;

        int c = num % 10;
        
        arr[a]++;
        arr[b]++;
        arr[c]++;

        return arr;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int> freq(10);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            freq[digits[i]]++;
        }

        for (int i = 100; i <= 998; i += 2) {
            vector<int> temp = count(i);
            bool flag = true;
            for (int j = 0; j < 10; ++j) {
                if (temp[j] > freq[j]) {
                    flag = false;
                }
            }

            if (flag) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};