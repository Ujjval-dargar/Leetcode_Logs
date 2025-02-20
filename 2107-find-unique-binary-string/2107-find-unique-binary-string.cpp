class Solution {
public:
    int bintoNum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans += pow(2, n - 1 - i);
            }
        }

        return ans;
    }

    string numtoBin(int num) {
        string ans = "";
        while (num > 0) {
            ans.push_back('0' + num % 2);
            num = num / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int, bool> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[bintoNum(nums[i])] = true;
        }

        string ans;

        for (int i = 0; i <= 16; ++i) {
            if (!mp[i]) {
                ans = numtoBin(i);
                break;
            }
        }

        int k = ans.size();
        string temp = "";
        if (k < n) {
            for (int i = k + 1; i <= n; ++i) {
                temp.push_back('0');
            }
        }

        return temp + ans;
    }
};