class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> freq;
        for (int i:deck){
            freq[i]++;
        }

        int ans = -1;
        for (auto &i:freq){
            if (ans==-1) ans = i.second;
            // cout<<i.second<<" "<<ans<<endl;
            ans = __gcd(ans,i.second);
        }

        return ans!=1;
    }
};