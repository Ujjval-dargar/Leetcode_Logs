class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        for (int i=0;i<n;++i){
            int l=i-1;
            int r=i+1;
            if (l==-1) l=n-1;
            if (r==n) r=0;

            ans+= (colors[i]!=colors[l] && colors[i]!=colors[r]);
        }

        return ans;
    }
};