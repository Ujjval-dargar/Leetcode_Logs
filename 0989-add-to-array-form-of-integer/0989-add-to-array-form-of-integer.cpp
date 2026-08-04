class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int i = nums.size()-1;
        int c = 0;
        vector<int> ans;
        while (k){
            int d = k%10;
            k = k/10;
            int s = 0;
            if (i >= 0) s = nums[i];
            ans.push_back((d+s+c)%10);
            c = (d+s+c)/10;
            i--;
            // cout << d << " " << s << " " << c << endl;
        }
        while (i >= 0){
            int s = nums[i];
            ans.push_back((s+c)%10);
            c = (s+c)/10;
            i--;
        }
        if (c) ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};