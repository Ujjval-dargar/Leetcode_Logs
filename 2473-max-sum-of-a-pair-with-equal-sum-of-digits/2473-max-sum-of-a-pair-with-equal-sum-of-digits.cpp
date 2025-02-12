class Solution {
public:
    int digitSum(int num) {
        int s = 0;
        while (num > 0) 
        {
            s += num % 10;
            num = num / 10;
        }
        return s;
    }

    int maximumSum(vector<int>& nums) 
    {
        int n = nums.size();

        int ans = -1;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; ++i) {

            int d = digitSum(nums[i]);

            if (mp[d].size() < 2) 
            {
                mp[d].push_back(nums[i]);
            } 
            else if (mp[d].size() == 2) 
            {
                int a = mp[d][0];
                int b = mp[d][1];

                if (nums[i] > min(a, b)) 
                {
                    if (a < b) 
                    {
                        mp[d][0] = nums[i];
                    } 
                    else 
                    {
                        mp[d][1] = nums[i];
                    }
                }
            }

            if (mp[d].size() == 2)
            {
                ans = max(ans, mp[d][0] + mp[d][1]);
            }
        }

        return ans;
    }
};