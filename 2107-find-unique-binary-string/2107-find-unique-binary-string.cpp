class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int n=nums.size();
        for (int i=0;i<n;++i){
            ans.push_back('0');
        }

        for (int i=0;i<n;++i){
            if (nums[i][i]=='0'){
                ans[i]='1';
            }
            else {
                ans[i]='0';
            }
        }

        return ans;
    }
};