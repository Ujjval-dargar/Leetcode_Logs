class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> freq;
        for (int i:nums) freq[i]++;

        auto it = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),it));
        int n = nums.size();
        int ans = 0;
        for (int i=0;i+1<n;++i){
            if (nums[i+1]-nums[i]==1){
                ans = max(ans,freq[nums[i+1]]+freq[nums[i]]);
            }
        }
        return ans;
    }
};