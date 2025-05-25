class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> same;
        unordered_map<string, int> different;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (words[i][0] == words[i][1])
                same[words[i]]++;
            else
                different[words[i]]++;
        }

        int ans = 0;
        bool odd_present=false;
        for (auto i:same){
            ans+=(i.second/2)*4;
            if (i.second%2==1) odd_present=true;
        }

        if (odd_present) ans+=2;

        // cout<<ans<<endl;
        
        for (auto i:different){
            string reversed;
            reversed.push_back(i.first[1]);
            reversed.push_back(i.first[0]);
            // cout<<i.first<<" "<<reversed<<" "<<i.second<<" "<<different[reversed]<<endl;
            while (i.second>0 && different[reversed]>0){
                // cout<<i.second<<" "<<different[reversed]<<endl;
                ans+=4;
                i.second--;
                different[reversed]--;
            }

            different[i.first]=i.second;

            cout<<endl;
        }

        return ans;
    }
};