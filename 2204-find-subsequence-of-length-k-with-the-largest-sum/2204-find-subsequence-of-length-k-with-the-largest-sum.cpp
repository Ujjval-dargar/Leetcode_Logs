class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<int>> temp1;
        for (int i=0;i<n;++i){
            temp1.push_back({nums[i],i});
        }

        sort(temp1.rbegin(),temp1.rend());

        vector<vector<int>> temp2;
        for (int i=0;i<k;++i){
            temp2.push_back({temp1[i][1],temp1[i][0]});
        }
        sort(temp2.begin(),temp2.end());

        vector<int> ans;
        for (auto &i:temp2){
            ans.push_back(i[1]);
        }

        return ans;
    }
};