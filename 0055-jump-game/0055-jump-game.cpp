class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxJump=0;
        int n=nums.size();
        for (int i=0;i<n;++i){
            if (i>mxJump){return false;}
            mxJump=max(mxJump,i+nums[i]);
        }

        return true;
    }
};