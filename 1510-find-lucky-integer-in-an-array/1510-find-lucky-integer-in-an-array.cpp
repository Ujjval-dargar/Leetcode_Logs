class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (int i:arr) mp[i]++;

        int ans = -1;
        for (int i:arr) if (i == mp[i]) ans=max(ans,i);

        return ans;
    }
};