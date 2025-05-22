class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> window;
        int n=nums.size();
        for (int i=0;i<n;++i){
            if (i>indexDiff) window.erase(nums[i-indexDiff-1]);

            auto f = window.lower_bound(nums[i]-valueDiff);

            if (f!=window.end() && abs(*f - nums[i])<=valueDiff) return true;

            window.insert(nums[i]);
        }

        return false;
    }
};