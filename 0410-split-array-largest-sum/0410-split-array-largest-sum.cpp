

class Solution {
public:

    int check(vector<int>&nums,int mx, int k){
        int n=nums.size();
        int cnt=1;
        int curr=nums[0];
        for (int i=1;i<n;++i){
            if (curr+nums[i]<=mx){
                curr+=nums[i];
            }else{
                curr=nums[i];
                cnt++;
            }
        }

        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);

        int ans = -1;
        while (l<=r){
            int mid=(r-l)/2+l;
            if (check(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};